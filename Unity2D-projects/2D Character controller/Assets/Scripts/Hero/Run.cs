using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Run : MonoBehaviour
{
    States stats;
    Rigidbody2D rb;

    void Start()
    {
        stats = GetComponent<States>();
        rb = GetComponent<Rigidbody2D>();
    }

    void FixedUpdate()
    {
        if (Input.GetKey(KeyCode.D) && !stats.sit && !stats.slide && stats.attack == 0 && stats.hardAttack == 0 && !stats.jumpAttack)//земля
        {
            transform.rotation = Quaternion.Euler(new Vector3(0, 0, 0));
            rb.velocity = new Vector2(12, rb.velocity.y);
        }
        else if (Input.GetKey(KeyCode.A) && !stats.sit && !stats.slide && stats.attack == 0 && stats.hardAttack == 0 && !stats.jumpAttack)
        {
            transform.rotation = Quaternion.Euler(new Vector3(0, 180, 0));
            rb.velocity = new Vector2(-12, rb.velocity.y);
        }
        else if (!stats.slide && stats.attack == 0 && stats.hardAttack == 0 && !stats.jumpAttack)
        {
            rb.velocity = new Vector2(0, rb.velocity.y);
        }
    }
}
