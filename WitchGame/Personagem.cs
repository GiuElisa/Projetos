using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Personagem : MonoBehaviour
{
    public Rigidbody2D rb;
    public float direcaoHorizontal = 0;
    public int contador = 0;
    public float intensidadeMovimentoHorizontal = 7;
    public int  intensidadePulo;

    private Vector3 facingRight;
    private Vector3 facingLeft;
    public float direcao;

    public Animator animate;

    // Start is called before the first frame update
    void Start()
    {
        this.rb = gameObject.GetComponent<Rigidbody2D>();
        this.rb.freezeRotation = true;

        facingRight = transform.localScale;
        facingLeft = transform.localScale;
        facingLeft.x = facingLeft.x * -1;

        animate = GetComponent<Animator>();
    }

    // Update is called once per frame
    void Update()
    {
        MovimentoPulo(10);
        MovimentoHorizontal(4);

        direcao = Input.GetAxis("Horizontal");
        rb.velocity = new Vector2(direcao * intensidadeMovimentoHorizontal, rb.velocity.y);

        if (direcao > 0)
        {
            transform.localScale = facingRight;
        }
        if (direcao < 0)
        {
            transform.localScale = facingLeft;
        }

        if(Input.GetAxis("Horizontal")!=0)
        {
            animate.SetBool("taCorrendo", true);
        }
        else
        {
            animate.SetBool("taCorrendo", false);
        }

     

    }
    void MovimentoPulo(float intensidadePulo = 5)
    {
        if (Input.GetButtonDown("Jump"))
        {
            rb.velocity = Vector2.up * intensidadePulo;

            animate.SetBool("taPulando", true);
        }
        if (rb.velocity.y == 0)
        {
            animate.SetBool("taPulando", false);
        }

    }
   
    void MovimentoHorizontal(float intensidade)
    {
        this.direcaoHorizontal = Input.GetAxis("Horizontal");
        float x = this.direcaoHorizontal * intensidade;
        float y = rb.velocity.y;
        Vector2 movimento = new Vector2(x, y);
        this.rb.velocity = movimento;
    }

    void OnCollisionEnter2D(Collision2D objeto)
    {
        if (objeto.gameObject.tag == "Coleta")
        {
            Destroy(objeto.gameObject);
            this.contador++;
            print(contador);
        }
        
        if (objeto.gameObject.tag == "Fim1")
        {
            SceneManager.LoadScene("fase2");
        }
        if (objeto.gameObject.tag == "Fim2")
        {
            SceneManager.LoadScene("fase3");
        }
        if (objeto.gameObject.tag == "Fim3")
        {
            SceneManager.LoadScene("fase4");
        }
        if (objeto.gameObject.tag == "Fim4")
        {
            SceneManager.LoadScene("Fim");
        }
        if (objeto.gameObject.tag == "morte")
        {
            Destroy(objeto.gameObject);
            SceneManager.LoadScene("game_over");
        }
        if (objeto.gameObject.tag == "Fim0")
        {
            SceneManager.LoadScene("fase1");
        }


        if (objeto.gameObject.tag == "bonus")
        {
            this.intensidadeMovimentoHorizontal = 10.0f;
            Destroy(objeto.gameObject);
        }
        if (objeto.gameObject.tag == "bonusbranco")
        {
            this.intensidadeMovimentoHorizontal = 7.0f;
            Destroy(objeto.gameObject);
        }


    }

    private void OnCollisionStay2D(Collision2D ficou)
    {
        if (ficou.gameObject.CompareTag("arremesso"))
        {
            this.intensidadePulo = 20;
        }
       
    }
    private void OnCollisionExit2D(Collision2D saiu)
    {

        if (saiu.gameObject.CompareTag("arremesso"))
        {
            this.intensidadePulo = 10;
        }
    }

}
