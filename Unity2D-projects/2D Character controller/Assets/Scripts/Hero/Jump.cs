using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Jump : MonoBehaviour
{
    States stats;
    Rigidbody2D rb;
    bool falling = true;

    void Start()
    {
        stats = GetComponent<States>();
        rb = GetComponent<Rigidbody2D>();
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Space) && stats.ground == true && stats.attack == 0 && stats.hardAttack == 0 && !stats.sit && !stats.floor)
            rb.AddForce(new Vector2(rb.velocity.x, 650));

        if (rb.velocity.y < 0 && falling && !stats.ground && !stats.jumpAttack)
        {
            falling = false;
            StartCoroutine(Fall());
        }
    }

    IEnumerator Fall()
    {
        float i = 0;

        while (!stats.ground)
        {
            if (stats.jumpAttack)
                break;

            rb.velocity = new Vector2(rb.velocity.x, i);
            i -= 0.4f;
            yield return new WaitForSeconds(0.01f);
        }

        falling = true;
    }
}
