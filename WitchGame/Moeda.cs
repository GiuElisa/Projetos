using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Moeda : MonoBehaviour
{
    public int contador = 0;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    void OnCollisionEnter2D(Collision2D objeto)
    {
        if (objeto.gameObject.tag == "Coleta")
        {
            Destroy(objeto.gameObject);
            this.contador++;
            print(contador);
        }
    }
}
