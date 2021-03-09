using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Slide : MonoBehaviour
{
    States stats;
    BoxCollider2D box;
    Rigidbody2D rb;
    bool start = false;

    void Start()
    {
        stats = GetComponent<States>();
        rb = GetComponent<Rigidbody2D>();
        box = GetComponent<BoxCollider2D>();
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.LeftShift) && !stats.slide && stats.ground && start == false && stats.attack == 0 && stats.hardAttack == 0)
            stats.slide = true;
        else if (Input.GetKeyDown(KeyCode.LeftShift) && !stats.ground && !stats.slide && start == false && stats.attack == 0 && stats.hardAttack == 0)
            StartCoroutine(Wait());

        if (stats.slide == true && stats.ground == true)
        {
            start = true;
            StartCoroutine(Slider());
        }
    }

    IEnumerator Wait()
    {
        while (!stats.ground)
        {
            yield return null;
        }
        
        stats.slide = true;
        yield return null;
    }

    IEnumerator Slider()
    {
        box.size = new Vector2(0.09f, 0.155f);
        box.offset = new Vector2(0.009f, -0.1f);

        if (stats.side == 0) 
            rb.velocity = new Vector2(15, rb.velocity.y);
        else
            rb.velocity = new Vector2(-15, rb.velocity.y);

        yield return new WaitForSeconds(0.4f);
        stats.slide = false;

        if (!stats.sit)
        {
            box.size = new Vector2(0.09f, 0.29f);
            box.offset = new Vector2(0.009f, -0.033f);
        }

        yield return new WaitForSeconds(0.5f);
        start = false;
    }
}
