#include "MagicProjectile.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

AMagicProjectile::AMagicProjectile(){
  CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
  CollisionComp->SetCollisionProfileName("Projectile");
  CollisionComp->SetupAttachment(RootComponent);

  ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("VFX"));
  ParticleComp->SetupAttachment(CollisionComp);

  MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
  MovementComp->InitialSpeed = 1000.f;
  MovementComp->bRotationFollowsVelocity = true;
  MovementComp->bInitialVelocityInLocalSpace = true;
}
