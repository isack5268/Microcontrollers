using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Sit : MonoBehaviour
{
    States stats;
    BoxCollider2D box;

    void Start()
    {
        stats = GetComponent<States>();
        box = GetComponent<BoxCollider2D>();
    }

    void Update()
    {
        if (Input.GetKey(KeyCode.S) && stats.ground && stats.attack == 0 && stats.hardAttack == 0 && !stats.slide )
        {
            if(Input.GetKeyDown(KeyCode.D))
                transform.rotation = Quaternion.Euler(new Vector3(0, 0, 0));
            else if(Input.GetKeyDown(KeyCode.A))
                transform.rotation = Quaternion.Euler(new Vector3(0, 180, 0));

            stats.sit = true;
            box.size = new Vector2(0.09f, 0.2f);
            box.offset = new Vector2(0.009f, -0.079f);
        }
        else if((!Input.GetKey(KeyCode.S) || !Input.GetKey(KeyCode.A) || stats.attack != 0 || stats.hardAttack != 0 || !stats.ground) && !stats.floor)
        {
            stats.sit = false;
            box.size = new Vector2(0.09f, 0.29f);
            box.offset = new Vector2(0.009f, -0.033f);
        }
    }
}
