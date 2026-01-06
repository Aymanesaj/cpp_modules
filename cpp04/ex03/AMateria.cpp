#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& other) { operator=(other); }

AMateria&    AMateria::operator=(const AMateria& other) { if (this != &other) {} return (*this);}

AMateria::AMateria(std::string const & type): type(type) {}

std::string const & AMateria::getType() const { return (type); }

void AMateria::use(ICharacter& target) { (void)target; }