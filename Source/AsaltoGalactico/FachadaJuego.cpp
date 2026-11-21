#include "FachadaJuego.h"

#include "Enemigo.h"
#include "FabricaFamiliaBasica.h"
#include "FabricaEnemigoResistente.h"
#include "ConstructorEnemigo.h"
#include "Engine/World.h"

// Crear enemigo básico mediante Abstract Factory
AEnemigo* FachadaJuego::CrearEnemigoBasico(
    UWorld* Mundo,
    const FVector& Posicion,
    const FRotator& Rotacion)
{
    if (Mundo == nullptr)
    {
        return nullptr;
    }

    FabricaFamiliaBasica Fabrica;

    return Fabrica.CrearEnemigo(
        Mundo,
        Posicion,
        Rotacion
    );
}

// Crear enemigo resistente mediante Factory Method
AEnemigo* FachadaJuego::CrearEnemigoResistente(
    UWorld* Mundo,
    const FVector& Posicion,
    const FRotator& Rotacion)
{
    if (Mundo == nullptr)
    {
        return nullptr;
    }

    FabricaEnemigoResistente Fabrica;

    return Fabrica.CrearEnemigo(
        Mundo,
        Posicion,
        Rotacion
    );
}

// Crear enemigo personalizado mediante Builder
AEnemigo* FachadaJuego::CrearEnemigoPersonalizado(
    UWorld* Mundo,
    const FVector& Posicion,
    const FRotator& Rotacion,
    float Vida,
    float Velocidad)
{
    if (Mundo == nullptr)
    {
        return nullptr;
    }

    ConstructorEnemigo Constructor;

    return Constructor
        .ConfigurarVida(Vida)
        .ConfigurarVelocidad(Velocidad)
        .Construir(Mundo, Posicion, Rotacion);
}