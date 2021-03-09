using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ground : MonoBehaviour
{
    RaycastHit2D hit1, hit2, hit3, hit4;
    BoxCollider2D box;
    States stats;
    Rigidbody2D rb;
    float distance1, distance2, distance3 = 10, distance4 = 10;
    public float size;

    void Start()
    {
        stats = GetComponent<States>();
        rb = GetComponent<Rigidbody2D>();
        box = GetComponent<BoxCollider2D>();
    }

    void Update()
    {
        if (stats.side == 0)
        {
            hit1 = Physics2D.Raycast(new Vector2(transform.position.x - 0.25f, transform.position.y - 1.25f), -Vector2.up);
            Debug.DrawRay(new Vector2(transform.position.x - 0.25f, transform.position.y - 1.25f), -Vector2.up, Color.green);

            hit2 = Physics2D.Raycast(new Vector2(transform.position.x + 0.38f, transform.position.y - 1.25f), -Vector2.up);
            Debug.DrawRay(new Vector2(transform.position.x + 0.38f, transform.position.y - 1.25f), -Vector2.up, Color.green);
        }
        else
        {
            hit1 = Physics2D.Raycast(new Vector2(transform.position.x - 0.38f, transform.position.y - 1.25f), -Vector2.up);
            Debug.DrawRay(new Vector2(transform.position.x - 0.38f, transform.position.y - 1.25f), -Vector2.up, Color.green);

            hit2 = Physics2D.Raycast(new Vector2(transform.position.x + 0.25f, transform.position.y - 1.25f), -Vector2.up);
            Debug.DrawRay(new Vector2(transform.position.x + 0.25f, transform.position.y - 1.25f), -Vector2.up, Color.green);
        }

        if (hit1.collider == null && hit2.collider == null)
        {
            distance1 = 10;
            distance2 = 10;
        }

        if (hit1.collider != null && hit1.collider.gameObject.tag == "Ground" && hit2.collider != null && hit2.collider.gameObject.tag == "Ground")
        {
            distance1 = Mathf.Abs(hit1.point.y - transform.position.y);
            distance2 = Mathf.Abs(hit2.point.y - transform.position.y);
        }

        if (distance1 <= 1.27 || distance2 <= 1.27)
            stats.ground = true;
        else stats.ground = false;

        if (stats.side == 0)
        {
            hit3 = Physics2D.Raycast(new Vector2(transform.position.x - 0.2f, transform.position.y + 0.35f), Vector2.up, 10);
            Debug.DrawRay(new Vector2(transform.position.x - 0.2f, transform.position.y + 0.35f), Vector2.up, Color.green);

            hit4 = Physics2D.Raycast(new Vector2(transform.position.x + 0.3f, transform.position.y + 0.35f), Vector2.up, 10);
            Debug.DrawRay(new Vector2(transform.position.x + 0.3f, transform.position.y + 0.35f), Vector2.up, Color.green);
        }
        else
        {
            hit3 = Physics2D.Raycast(new Vector2(transform.position.x - 0.31f, transform.position.y + 0.35f), Vector2.up, 10);
            Debug.DrawRay(new Vector2(transform.position.x - 0.31f, transform.position.y + 0.35f), Vector2.up, Color.green);

            hit4 = Physics2D.Raycast(new Vector2(transform.position.x + 0.2f, transform.position.y + 0.35f), Vector2.up, 10);
            Debug.DrawRay(new Vector2(transform.position.x + 0.2f, transform.position.y + 0.35f), Vector2.up, Color.green);
        }

        if (hit3.collider == null && hit4.collider == null)
        {
            distance3 = 10;
            distance4 = 10;
        }

        if (hit3.collider != null && hit4.collider != null && hit3.collider.gameObject.tag != "Player" && hit4.collider.gameObject.tag != "Player")
        {
            distance3 = Mathf.Abs(hit3.point.y - transform.position.y);
            distance4 = Mathf.Abs(hit4.point.y - transform.position.y);
        }

        if ((distance3 <= 0.9 || distance4 <= 0.9) && stats.ground)
        {
            if (Input.GetKeyDown(KeyCode.D))
                transform.rotation = Quaternion.Euler(new Vector3(0, 0, 0));
            else if (Input.GetKeyDown(KeyCode.A))
                transform.rotation = Quaternion.Euler(new Vector3(0, 180, 0));

            stats.floor = true;
            stats.sit = true;
            box.size = new Vector2(0.09f, 0.2f);
            box.offset = new Vector2(0.009f, -0.079f);
        }
        else if(stats.ground)
        {
            stats.floor = false;
        }
    }
}
