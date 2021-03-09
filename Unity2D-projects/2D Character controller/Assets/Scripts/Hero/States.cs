using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class States : MonoBehaviour
{
    public float speed = 0;
    public float side;
    public bool jumpAttack;
    public bool ground;
    public bool floor;
    public bool slide;
    public bool sit;
    public int attack;
    public int hardAttack;
    Rigidbody2D rb;

    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
    }

    void Update()
    {
        if (rb.velocity.x != 0)
            speed = 1;
        else speed = 0;

        side = transform.rotation.eulerAngles.y;
    }
}
