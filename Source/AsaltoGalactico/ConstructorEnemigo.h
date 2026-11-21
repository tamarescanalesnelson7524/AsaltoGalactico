#pragma once

#include "CoreMinimal.h"

class AEnemigo;
class UWorld;

class ConstructorEnemigo
{
private:
    float Vida;
    float Velocidad;

public:
    ConstructorEnemigo();

    ConstructorEnemigo& ConfigurarVida(float NuevaVida);

    ConstructorEnemigo& ConfigurarVelocidad(float NuevaVelocidad);

    AEnemigo* Construir(
        UWorld* Mundo,
        const FVector& Posicion,
        const FRotator& Rotacion
    ) const;
};