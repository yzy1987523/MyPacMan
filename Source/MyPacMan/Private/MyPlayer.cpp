#include "public/MyPlayer.h"
#include "UObject/ConstructorHelpers.h"
AMyPlayer::AMyPlayer()
{
	PrimaryActorTick.bCanEverTick = true;//�����ʱ��ÿ֡����
	USphereComponent*SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));//����һ���Ӷ��󣬰���USphereComponent���������ΪRootComponent����������ײ��
	RootComponent = SphereComponent;//��SphereComponent����Ϊ�����
	SphereComponent->InitSphereRadius(40);//������İ뾶
	SphereComponent->SetCollisionProfileName(TEXT("Pawn"));//??

	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));//����һ��Mesh���
	SphereVisual->AttachTo(RootComponent);//��Mesh��ӵ�Root

	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("Ball'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (SphereVisualAsset.Succeeded()) {
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
	}
	SphereVisual->SetWorldScale3D(FVector(0.3, 0.3, 0.3));
	SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -20));
	SphereComponent->SetSphereRadius(16);
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

