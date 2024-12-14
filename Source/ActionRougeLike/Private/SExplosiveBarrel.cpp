// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplosiveBarrel.h"

#include "SMagicProjectile.h"
#include "Components/BoxComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"

// Sets default values
ASExplosiveBarrel::ASExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	meshComp->SetupAttachment(RootComponent);
	meshComp->SetSimulatePhysics(true);
	meshComp->SetNotifyRigidBodyCollision(true);
	meshComp->BodyInstance.SetCollisionProfileName("PhysicsActor");
	
	

	radialForceComp = CreateDefaultSubobject<URadialForceComponent>("RadialComp");
	radialForceComp->SetupAttachment(meshComp);
	radialForceComp->bImpulseVelChange = true;
	
	
}

// Called when the game starts or when spawned
void ASExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	meshComp->OnComponentHit.AddDynamic(this,&ASExplosiveBarrel::OnHit);
	radialForceComp->Radius = impulseRadius;
	radialForceComp->ImpulseStrength = impulseForce;
}

// Called every frame
void ASExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASExplosiveBarrel::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (!isExplode && OtherActor && OtherActor->IsA(ASMagicProjectile::StaticClass()))
	{
		UE_LOG(LogTemp,Warning,TEXT("Explode"))
		radialForceComp->FireImpulse();
	
		FTimerHandle TimerHandle;
	
		GetWorld()->GetTimerManager().SetTimer(
			TimerHandle,
			[this]()
			{
				Destroy();
			},
			destroyDelay,
			false
			);
		isExplode = true;
	}
	
}


