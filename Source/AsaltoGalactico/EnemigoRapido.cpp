// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoRapido.h"

AEnemigoRapido::AEnemigoRapido()
{
    Vida = 60.0f;
    Velocidad = 400.0f;
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaRoja(
        TEXT("/Game/NavesEnemigos/StarSparrow07.StarSparrow07")
    );

    if (MallaRoja.Succeeded())
    {
        MallaEnemigo->SetStaticMesh(MallaRoja.Object);
        MallaEnemigo->SetRelativeScale3D(FVector(0.15f, 0.15f, 0.15f));
    }
}