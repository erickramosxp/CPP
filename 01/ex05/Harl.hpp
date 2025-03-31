#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl {
    
    private:
        struct Complaint {
            std::string level;
            void (Harl::*function)();
        };
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public:
        Harl(void);
        Complaint complains[4];
        void complain( std::string level );
    
};


#endif