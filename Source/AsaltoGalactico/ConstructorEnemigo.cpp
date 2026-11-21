#include "ConstructorEnemigo.h"
#include "Enemigo.h"
#include "Engine/World.h"

ConstructorEnemigo::ConstructorEnemigo()
{
    Vida = 100.0f;
    Velocidad = 0.0f;
}

ConstructorEnemigo& ConstructorEnemigo::ConfigurarVida(float NuevaVida)
{
    Vida = FMath::Max(0.0f, NuevaVida);
    return *this;
}

ConstructorEnemigo& ConstructorEnemigo::ConfigurarVelocidad(float NuevaVelocidad)
{
    Velocidad = FMath::Max(0.0f, NuevaVelocidad);
    return *this;
}

AEnemigo* ConstructorEnemigo::Construir(
    UWorld* Mundo,
    const FVector& Posicion,
    const FRotator& Rotacion
) const
{
    if (Mundo == nullptr)
    {
        return nullptr;
    }

    AEnemigo* NuevoEnemigo = Mundo->SpawnActor<AEnemigo>(
        AEnemigo::StaticClass(),
        Posicion,
        Rotacion
    );

    if (NuevoEnemigo != nullptr)
    {
        NuevoEnemigo->ConfigurarVida(Vida);
        NuevoEnemigo->ConfigurarVelocidad(Velocidad);
    }

    return NuevoEnemigo;
}