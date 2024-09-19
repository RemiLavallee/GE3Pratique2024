// Fill out your copyright notice in the Description page of Project Settings.


#include "Torch.h"
#include "NiagaraComponent.h"
#include "TorcheManager.h"

// Sets default values
ATorch::ATorch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	CylinderMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cylinder"));
	CylinderMesh->SetupAttachment(RootComponent);

	SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sphere"));
	SphereMesh->SetupAttachment(RootComponent);

	TorchFire = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Torch"));
	TorchFire->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ATorch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATorch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATorch::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if(TorcheManager->ValidateTorchHit(this))
	{
		SphereMesh->SetMaterial(0, TorchMaterial);
		TorchFire->SetVariableFloat(TEXT("FireRate"), 120.f);
	}
}