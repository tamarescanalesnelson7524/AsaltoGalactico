// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FondoEspacial.generated.h"

UCLASS()
class ASALTOGALACTICO_API AFondoEspacial : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFondoEspacial();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Plano que mostrará el fondo espacial
	UPROPERTY(VisibleAnywhere, Category = "Fondo Espacial")
	class UStaticMeshComponent* MallaFondo;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
