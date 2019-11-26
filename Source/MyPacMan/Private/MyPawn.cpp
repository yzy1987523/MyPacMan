// Fill out your copyright notice in the Description page of Project Settings.


#include "public/MyPawn.h"
#include "UObject/ConstructorHelpers.h"
// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("1"));//����һ���Ӷ��󣬰���USphereComponent���������ΪRootComponent����������ײ��
	RootComponent = SphereComponent;//��SphereComponent����Ϊ�����
	SphereComponent->InitSphereRadius(40);//������İ뾶
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));//??

	 SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("2"));//����һ��Mesh���
	SphereVisual->AttachTo(RootComponent);//��Mesh��ӵ�Root

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("3'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (SphereVisualAsset.Succeeded()) {
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
	}
	SphereVisual->SetWorldScale3D(FVector(0.3, 0.3, 0.3));
	SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -20));
	SphereComponent->SetSphereRadius(16);
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

