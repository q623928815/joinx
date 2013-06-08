#pragma once

#include <cstdint>
#include <iostream>
#include <map>
#include <memory>
#include <string>

class CommandBase {
public:
    typedef std::shared_ptr<CommandBase> ptr;

    virtual ~CommandBase() {}

    virtual ptr create(int argc, char** argv) = 0;
    virtual void exec() = 0;
    virtual std::string name() const = 0;
    virtual std::string description() const = 0;
    virtual bool hidden() const {
        return false;
    }

    ptr subCommand(const std::string& name, int argc, char** argv) const;
    void registerSubCommand(const ptr& app);
    void describeSubCommands(std::ostream& s, const std::string& indent = "\t");

protected:
    typedef std::map<std::string, ptr> SubCommandMap;
    SubCommandMap _subCmds;
};