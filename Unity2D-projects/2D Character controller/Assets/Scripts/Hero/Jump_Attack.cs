using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Jump_Attack : MonoBehaviour
{
    Rigidbody2D rb;
    States stats;

    void Start()
    {
        stats = GetComponent<States>();
        rb = GetComponent<Rigidbody2D>();
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Mouse0) && !stats.ground && !stats.floor)
            StartCoroutine(Fall());
        else if (stats.ground && stats.jumpAttack)
            StartCoroutine(End());
    }

    IEnumerator Fall()
    {
        stats.jumpAttack = true;
        yield return new WaitForSeconds(0.2f);

        while (!stats.ground)
        {
            rb.velocity = new Vector2(0, -20);
            yield return new WaitForSeconds(0.01f);
        }
    }

    IEnumerator End()
    {
        yield return new WaitForSeconds(0.3f);
        stats.jumpAttack = false;
    }
}
