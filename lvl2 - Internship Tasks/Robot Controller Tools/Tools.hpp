#ifndef TOOLS_HPP
#define TOOLS_HPP

//-- Includes Robot Header
#include "Robot.hpp"

//-- Class Definition
class Tools {
    private:
    public:
    //-- Default Constructor
    Tools();
    //-- Destructor
    ~Tools();
    struct Read {
        struct ClientCNF {
            //-- Get Needed Client's System Info
            bool os() noexcept;
            //-- Read Client's Display Resolution for Configuring
            bool monitor() noexcept;
        };
        ClientCNF client;
        struct RobotCNF {
            //-- Get Needed Robot's System Info
            bool os() noexcept;
        };
        RobotCNF robot;
    };
    Read read;
};

#endif // TOOLS_HPP