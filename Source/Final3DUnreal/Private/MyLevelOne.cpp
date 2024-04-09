// Fill out your copyright notice in the Description page of Project Settings.


#include "MyLevelOne.h"

// Sets default values
AMyLevelOne::AMyLevelOne()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyLevelOne::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyLevelOne::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

