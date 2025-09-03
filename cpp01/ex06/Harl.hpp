#include <iostream>

class Harl
{
private:
public:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
    int GetLevel( std::string level );
};