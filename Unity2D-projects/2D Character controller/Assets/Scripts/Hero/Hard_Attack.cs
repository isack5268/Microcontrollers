using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Hard_Attack : MonoBehaviour
{
    Rigidbody2D rb;
    States stats;
    bool start = false;
    bool next = true;

    void Start()
    {
        stats = GetComponent<States>();
        rb = GetComponent<Rigidbody2D>();
    }

    void Update()
    {
        if (Input.GetKeyDown(KeyCode.Mouse1) && stats.ground && start == false && !stats.floor)
        {
            start = true;
            StartCoroutine(Transfer_Animation());
        }

        if (stats.slide)
            stats.hardAttack = 0;
    }

    IEnumerator Transfer_Animation()
    {
        stats.hardAttack++;

        if (stats.hardAttack <= 3 && !stats.slide && stats.attack == 0)
        {
            int end = 0;

            if (Input.GetKey(KeyCode.D))
                transform.rotation = Quaternion.Euler(new Vector3(0, 0, 0));
            else if (Input.GetKey(KeyCode.A))
                transform.rotation = Quaternion.Euler(new Vector3(0, 180, 0));

            yield return new WaitForSeconds(0.01f);

            if (stats.hardAttack < 3)
                StartCoroutine(Step());
            else StartCoroutine(Jump());

            yield return new WaitForSeconds(0.15f);

            while (next)
            {
                if (!stats.ground && stats.hardAttack != 3)
                    next = false;

                if (end == 150)
                    next = false;

                if (Input.GetKeyDown(KeyCode.LeftShift) && !stats.slide)
                {
                    yield return new WaitForSeconds(0.2f - end / 1000);
                    stats.slide = true;
                    yield return new WaitForSeconds(0.5f);
                    next = true;
                    start = false;
                    break;
                }             

                if (Input.GetKeyDown(KeyCode.Mouse1))
                {
                    yield return new WaitForSeconds(0.2f - end / 1000);
                    StartCoroutine(Transfer_Animation());
                    break;
                }

                yield return new WaitForSeconds(0.001f);
                end++;
            }

            if (!next)
            {
                yield return null;
                stats.hardAttack = 0;
                next = true;
                start = false;
            }
        }
        else
        {
            yield return null;
            stats.hardAttack = 0;
            next = true;
            start = false;
        }
    }

    IEnumerator Step()
    {
        if (stats.side == 0)
            rb.velocity = new Vector2(15, rb.velocity.y);
        else rb.velocity = new Vector2(-15, rb.velocity.y);

        if (stats.slide)
            rb.velocity = new Vector2(0, rb.velocity.y);
        else
        {
            yield return new WaitForSeconds(0.05f);
            rb.velocity = new Vector2(0, rb.velocity.y);
        }
    }

    IEnumerator Jump()
    {
        if (stats.side == 0)
            rb.velocity = new Vector2(15, 4);
        else rb.velocity = new Vector2(-15, 4);

        if (stats.slide)
            rb.velocity = new Vector2(0, rb.velocity.y);
        else
        {
            yield return new WaitForSeconds(0.05f);
            rb.velocity = new Vector2(0, rb.velocity.y);
        }
    }
}
