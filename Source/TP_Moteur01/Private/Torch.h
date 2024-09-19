// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Torch.generated.h"

class ATorcheManager;

UCLASS()
class ATorch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATorch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	ATorcheManager* TorcheManager;
	
private:
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CylinderMesh;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SphereMesh;

	UPROPERTY(VisibleAnywhere)
	class UNiagaraComponent* TorchFire;

	UPROPERTY(EditAnywhere)
	UMaterial* TorchMaterial;
};
