// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectable.h"
#include "UObject/ConstructorHelpers.h"
// Sets default values
ACollectable::ACollectable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;//改为false，即不会调用Tick
	SetActorEnableCollision(true);

	CollectableMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CollectableMesh"));
	BaseCollisionMesh = CreateDefaultSubobject<USphereComponent>(TEXT("BaseCollisionMesh"));

	CollectableMesh->AttachTo(BaseCollisionMesh);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Sphere(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere'"));
	if (Sphere.Succeeded()) {
		CollectableMesh->SetStaticMesh(Sphere.Object);
	}
	CollectableMesh->SetWorldScale3D(FVector(0.3, 0.3, 0.3));
	BaseCollisionMesh->SetSphereRadius(16);
}

// Called when the game starts or when spawned
void ACollectable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollectable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

