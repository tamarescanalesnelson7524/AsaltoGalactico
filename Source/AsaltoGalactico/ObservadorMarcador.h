#pragma once

#include "CoreMinimal.h"
#include "ObservadorEnemigo.h"

class ObservadorMarcador : public ObservadorEnemigo
{
private:
    int Puntuacion;

public:
    ObservadorMarcador();

    virtual void NotificarEnemigoDestruido() override;

    int ObtenerPuntuacion() const;
};