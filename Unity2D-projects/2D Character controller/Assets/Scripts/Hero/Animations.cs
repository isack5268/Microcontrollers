using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Animations : MonoBehaviour
{
    Animator anim;
    States stats;

    void Start()
    {
        anim = GetComponent<Animator>();
        stats = GetComponent<States>();
    }

    void Update()
    {
        anim.SetFloat("Speed", stats.speed);
        anim.SetBool("Ground", stats.ground);
        anim.SetBool("Sit", stats.sit);
        anim.SetBool("Slide", stats.slide);
        anim.SetInteger("Attack", stats.attack);
        anim.SetInteger("Hard_Attack", stats.hardAttack);
        anim.SetBool("Jump_Attack", stats.jumpAttack);
    }
}
