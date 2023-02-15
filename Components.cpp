//
//  Components.cpp
//  BSv0.3
//
//  Created by Jered Stevens on 2/9/23.
//

#include "Components.hpp"

/**************************************************
 *  Implementation for Struct Health
 **************************************************/

Health::Health()
{
    sHealth = 100;
};

Health::Health(const double x)
{
    sHealth = x;
};

double Health::getHealth()
{
    return sHealth;
    
};

void Health::setHealth(const double h)
{
    sHealth = h;
    
};

/**************************************************
 *  Implementation for Struct Melee
 **************************************************/

Melee::Melee()
{
    meleeDamage = .1; // Meters
    meleeRange = .5; // Meters
}

Melee::Melee(const double mDam, const double mRange)
{
    meleeDamage = mDam;
    meleeRange = mRange;
}

void Melee::setDamageAndRange(const double mDam, const double mRange)
{
    meleeDamage = mDam;
    meleeRange = mRange;
}

void Melee::setDamage(const double mDam)
{
    meleeDamage = mDam;
}

void Melee::setRange(const double mRange)
{
    meleeRange = mRange;
}

double Melee::getDamage()
{
    return meleeDamage;
}

double Melee::getRange()
{
    return meleeRange;
}
