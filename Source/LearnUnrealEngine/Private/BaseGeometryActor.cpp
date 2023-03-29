// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();
	
	//PrintTypes();
	//PrintStringTypes();
}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseGeometryActor::PrintTypes()
{
	int32 WeaponsNum = 4;
	int32 KillsNum = 7;
	float Health = 34.67394875;
	bool IsFall = false;
	bool HasWeapon = true;

	UE_LOG(LogTemp, Display, TEXT("Weapons num = %d, kills num = %i"), WeaponsNum, KillsNum);
	UE_LOG(LogTemp, Display, TEXT("Health = %f"), Health);
	UE_LOG(LogTemp, Display, TEXT("Health = %.2f"), Health);
	UE_LOG(LogTemp, Display, TEXT("Is fall = %d"), IsFall);
	UE_LOG(LogTemp, Display, TEXT("Has weapon = %d"), static_cast<int>(HasWeapon));
}

void ABaseGeometryActor::PrintStringTypes()
{
	FString Name = "John Connor";
	UE_LOG(LogBaseGeometry, Display, TEXT("Name: %s"), *Name);

	int32 WeaponsNum = 4;
	float Health = 34.67394875;
	bool IsFall = false;

	FString WeaponsNumStr = "Weapons num = " + FString::FromInt(WeaponsNum);
	FString HealthStr = "Health = " + FString::SanitizeFloat(Health);
	FString IsFallStr = "Is fall = " + FString(IsFall ? "true" : "false");

	FString Stats = FString::Printf(TEXT(" \n == All stats == \n %s \n %s \n %s"), *WeaponsNumStr, *HealthStr, *IsFallStr);

	UE_LOG(LogBaseGeometry, Warning, TEXT("%s"), *Stats);

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Emerald, Name);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, Stats, true, FVector2D(1.5f, 1.5f));
}

