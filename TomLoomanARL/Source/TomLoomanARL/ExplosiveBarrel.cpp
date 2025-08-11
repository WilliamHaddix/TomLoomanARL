#include "ExplosiveBarrel.h"

#include "MagicProjectile.h"
#include "Particles/ParticleSystemComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"

DEFINE_LOG_CATEGORY(LogBarrel);

AExplosiveBarrel::AExplosiveBarrel() {
   StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Collision"));
   RootComponent = StaticMeshComp;
   StaticMeshComp->SetCollisionProfileName("WorldDynamic");
   StaticMeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
   StaticMeshComp->SetCollisionResponseToAllChannels(ECR_Block);
   StaticMeshComp->SetNotifyRigidBodyCollision(true);

   ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("VFX"));
   ParticleComp->SetupAttachment(RootComponent);

   RadialForce = CreateDefaultSubobject<URadialForceComponent>(TEXT("RadialForce"));
   RadialForce->SetupAttachment(StaticMeshComp);
   RadialForce->Radius = 700.f;
   RadialForce->Falloff = RIF_Constant;
   RadialForce->ImpulseStrength = 2000.f;
   RadialForce->bImpulseVelChange = true;
   RadialForce->bAutoActivate = false;
}

void AExplosiveBarrel::BeginPlay()
{
   Super::BeginPlay();

   // Bind hit event
   StaticMeshComp->OnComponentHit.AddDynamic(this, &AExplosiveBarrel::OnHit);
}

void AExplosiveBarrel::OnHit(UPrimitiveComponent *HitComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit)
{
   if (auto* Projectile = Cast<AMagicProjectile>(OtherActor))
   {
      Explode();
   }
}

void AExplosiveBarrel::Explode()
{
   RadialForce->FireImpulse();
}