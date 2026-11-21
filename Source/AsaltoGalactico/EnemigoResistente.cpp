// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoResistente.h"

AEnemigoResistente::AEnemigoResistente()
{
    Vida = 200.0f;
    Velocidad = 150.0f;
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaVerde(
        TEXT("/Game/NavesEnemigos/StarSparrow21.StarSparrow21")
    );

    if (MallaVerde.Succeeded())
    {
        MallaEnemigo->SetStaticMesh(MallaVerde.Object);
        MallaEnemigo->SetRelativeScale3D(FVector(0.15f, 0.15f, 0.15f));
    }
}