#include "FabricaFamiliaAvanzada.h"

#include "EnemigoRapido.h"
#include "ProyectilAvanzado.h"
#include "Engine/World.h"

FabricaFamiliaAvanzada::FabricaFamiliaAvanzada()
{
}

FabricaFamiliaAvanzada::~FabricaFamiliaAvanzada()
{
}

AEnemigo* FabricaFamiliaAvanzada::CrearEnemigo(
    UWorld* Mundo,
    const FVector& Posicion,
    const FRotator& Rotacion
) const
{
    if (Mundo == nullptr)
    {
        return nullptr;
    }

    return Mundo->SpawnActor<AEnemigoRapido>(
        AEnemigoRapido::StaticClass(),
        Posicion,
        Rotacion
    );
}

AAsaltoGalacticoProjectile* FabricaFamiliaAvanzada::CrearProyectil(
    UWorld* Mundo,
    const FVector& Posicion,
    const FRotator& Rotacion
) const
{
    if (Mundo == nullptr)
    {
        return nullptr;
    }

    return Mundo->SpawnActor<AProyectilAvanzado>(
        AProyectilAvanzado::StaticClass(),
        Posicion,
        Rotacion
    );
}