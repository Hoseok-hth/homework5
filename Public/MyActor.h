// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

#define _EVENT_PROBABILITY_ = 50

UCLASS()
class MYPROJECT3_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void move();
	virtual int32_t step();
	virtual bool is_event();
	TArray<FVector2D> VectorArray;
	int Event_Count;
	float Total_Distance;

};
