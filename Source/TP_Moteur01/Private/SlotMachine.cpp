// Fill out your copyright notice in the Description page of Project Settings.


#include "SlotMachine.h"

// Sets default values
ASlotMachine::ASlotMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	ReelsComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Reels"));
	ReelsComponent->SetupAttachment(Root);

	LeverComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Lever"));
	LeverComponent->SetupAttachment(Root);

	ReelLeftMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReelLeftMesh"));
	ReelLeftMesh->SetupAttachment(ReelsComponent);

	ReelMidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReelMidMesh"));
	ReelMidMesh->SetupAttachment(ReelsComponent);

	ReelRightMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReelRightMesh"));
	ReelRightMesh->SetupAttachment(ReelsComponent);

	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxMesh"));
	BoxMesh->SetupAttachment(Root);

	WinButtonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WinButtonMesh"));
	WinButtonMesh->SetupAttachment(BoxMesh);

}

// Called when the game starts or when spawned
void ASlotMachine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASlotMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASlotMachine::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
}

