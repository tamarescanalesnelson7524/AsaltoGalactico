// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObservadorEnemigo.h"
#include "Enemigo.generated.h"

UCLASS()
class ASALTOGALACTICO_API AEnemigo : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemigo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Malla visual y componente principal de colision
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemigo")
	class UStaticMeshComponent* MallaEnemigo;

	// Vida inicial del enemigo
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemigo")
	float Vida;

	// Velocidad del enemigo
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemigo")
	float Velocidad;

	TArray<ObservadorEnemigo*> Observadores;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Funcion que se ejecutara cuando el enemigo reciba un impacto
	UFUNCTION()
	void RecibirImpacto(float Danio);

	// Consultar la vida actual
	UFUNCTION(BlueprintCallable, Category = "Enemigo")
	float ObtenerVida() const;

	// Consultar si el enemigo ha sido destruido
	UFUNCTION(BlueprintCallable, Category = "Enemigo")
	bool EstaDestruido() const;

	//consulta la velocidad 
	UFUNCTION(BlueprintCallable, Category = "Enemigo")
	float ObtenerVelocidad() const;

	// Configurar la vida del enemigo
	void ConfigurarVida(float NuevaVida);

	// Configurar la velocidad del enemigo
	void ConfigurarVelocidad(float NuevaVelocidad);

	// Registrar un observador
	void AgregarObservador(ObservadorEnemigo* Observador);

	// Notificar a los observadores
	void NotificarDestruccion();
};
