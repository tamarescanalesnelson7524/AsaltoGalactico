#pragma once

#include "CoreMinimal.h"

class UWorld;
class AEnemigo;

class FachadaJuego
{
public:

    // Crear un enemigo básico
    AEnemigo* CrearEnemigoBasico(
        UWorld* Mundo,
        const FVector& Posicion,
        const FRotator& Rotacion
    );

    // Crear un enemigo resistente
    AEnemigo* CrearEnemigoResistente(
        UWorld* Mundo,
        const FVector& Posicion,
        const FRotator& Rotacion
    );

    // Crear un enemigo personalizado mediante Builder
    AEnemigo* CrearEnemigoPersonalizado(
        UWorld* Mundo,
        const FVector& Posicion,
        const FRotator& Rotacion,
        float Vida,
        float Velocidad
    );
};