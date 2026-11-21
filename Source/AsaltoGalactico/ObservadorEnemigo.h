#pragma once

#include "CoreMinimal.h"

class ObservadorEnemigo
{
public:

    // Funcion que se ejecutara cuando un enemigo sea destruido
    virtual void NotificarEnemigoDestruido() = 0;

    virtual ~ObservadorEnemigo() {}
};