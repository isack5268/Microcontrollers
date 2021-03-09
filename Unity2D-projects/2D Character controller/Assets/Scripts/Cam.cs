using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cam : MonoBehaviour
{
    public GameObject player;
    Transform ico;

    void Start()
    {
        ico = player.GetComponent<Transform>();   
    }

    
    void FixedUpdate()
    {
        transform.position = new Vector3(ico.position.x, ico.position.y + 3, -10);
    }
}
