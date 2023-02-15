//
//  Components.hpp
//  BSv0.3
//
//  Created by Jered Stevens on 2/9/23.
//

#ifndef Components_hpp
#define Components_hpp

#include <stdio.h>

struct Health
{
private:
    double sHealth;
public:
    Health();
    Health(const double x);
    double getHealth();
    void setHealth(const double h);
};

struct Melee
{
private:
    double meleeDamage;
    double meleeRange;
public:
    Melee();
    Melee(const double mDam, const double mRange);
    void setDamageAndRange(const double mDam, const double mRange);
    void setDamage(const double mDam);
    void setRange(const double mRange);
    double getDamage();
    double getRange();
};

#endif /* Components.hpp */
