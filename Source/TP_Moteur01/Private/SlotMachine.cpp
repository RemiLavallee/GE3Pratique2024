// Fill out your copyright notice in the Description page of Project Settings.


#include "SlotMachine.h"

#include "BlendSpaceAnalysis.h"
#include "IntVectorTypes.h"
#include "Algo/RandomShuffle.h"
#include "Kismet/GameplayStatics.h"

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

	PivotLeverMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PivotLeverMesh"));
	PivotLeverMesh->SetupAttachment(LeverComponent);

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
	
	LeverAngle += DeltaTime * 50.0f;

	LeverAngle = FMath::Min(LeverAngle, 0.0f);

	FRotator NewRotation;
	NewRotation.Yaw = 0.0f;
	NewRotation.Pitch = LeverAngle;
	NewRotation.Roll = 90.0f;

	PivotLeverMesh->SetRelativeRotation(NewRotation);
}

void ASlotMachine::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if(LeverAngle == 0)
	{
		LeverAngle = -45.0f;
	
		FRotator NewRotation(LeverAngle, 0.0f, 90.0f);

		PivotLeverMesh->SetRelativeRotation(NewRotation);

		SpinReelsWithDelay();
	}
}

void ASlotMachine::Spin(UStaticMeshComponent* Reels, float& ReelAngle)
{
	int32 Random = FMath::RandRange(0,15);

	float FixedValue = 22.5f;

	int Result = Random * FixedValue;

	ReelAngle = Result;

	FRotator NewRotation;
	NewRotation.Pitch = Result;
	NewRotation.Yaw = 0.0f;
	NewRotation.Roll = 90.0f;

	Reels->SetRelativeRotation(NewRotation);
}

void ASlotMachine::TriggerDelay(float DelayTime, TFunction<void()> Callback, FTimerHandle& TimerHandle)
{
	GetWorldTimerManager().SetTimer(TimerHandle, [Callback]()
	{
		if(Callback)
		{
			Callback();
		}
	}, DelayTime, false);
}

void ASlotMachine::SpinReelsWithDelay()
{
	Spin(ReelLeftMesh, ReelLeftAngle);

	TriggerDelay(1.0f,[this]() { Spin(ReelMidMesh, ReelMidAngle); }, ReelMidHandle);

	TriggerDelay(2.0f,[this]() { Spin(ReelRightMesh, ReelRightAngle); CheckConditionToWin(); }, ReelRightHandle);
}

void ASlotMachine::CheckConditionToWin()
{
	if(ReelLeftHandle == ReelMidHandle || ReelLeftAngle == ReelRightAngle || ReelMidAngle == ReelRightAngle || ReelMidAngle == ReelLeftAngle)
	{
		SetWinMaterial();
	}
	else
	{
		SetDefaultMaterial();
	}
}

void ASlotMachine::SetWinMaterial()
{
	WinButtonMesh->SetMaterial(0, WinMaterial);
}

void ASlotMachine::SetDefaultMaterial()
{
	WinButtonMesh->SetMaterial(0, DefaultMaterial);
}

