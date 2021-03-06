# img to ASCII
img to ASCII is a program to convert images to **ASCII art** programmed in C++!

    
                                                         "l+~i!I:^.   .^":;Ill,.    
                     .""^`".                               `I+]]]]?!"Ii~~~iI".      
                      ";i~~il:"  .`":IIllI;.           ."`````^;+]]]]~~~~il!iiii!I:"
              ."^,::::,^`;i~~~~I~?]]]]-i;^.        `,I!~~~~~~~~~!!+-]_????-___++~~~i
             :!~+-?]]]]]]?+_~~?]]]+l:`"..         ",""""^^^^```:?||\\~Iii!lI:^"     
                   .`";li~+_--[-~!i~~~~~i!l;""              .:?)))1~`  ."Ii~~~~I"   
                .`:li~~~~l;"l\\\\]^`^",::;Il!iI"          .;[)))1~"       .^;i~~l   
               .I~~~iI,^.    `[))){;                     :[))))-`            .^:^   
               `I;"".         "?))))~.                 `-)))){;                     
                               "]))))-.              .l1))))-"                      
                                `{))))-.            "-)))))i.                       
                                 ;)))))i           ^}))))1;                         
                                 .]))))),         "{))))1;                          
                                  ;)))))].       ^{)))))I                           
                                  .1))11{""""""""-[}}{1+                            
                            ."``^^"I;:::::::::::::::::::,,""^^`"..                  
                      ."`^",::::::::::::::::::::::::::::::::::::::""^`..            
                 ."`^,:::::::::::::::::::::::::::::::::::::::::::::::::,"`".        
    ;ll;,"    .^,Ii_---_+iI;;;;;;I!+_---_~l;;;;;;;Ii+----+iI;;;;;;I!~_---_+l:^"    .
    ";I!_}}[??}{1}-iI;;l~]{{{}}{{{]~l;;;l+[{{{}}{{{?iI;;Ii?{{{}}{{1[+l;;;l+[{{{]?][{
    .."".            ."".             ."".            ."".             ."".

_img to ASCII_ has several optional command line options:
<ul style="list-style: none">
    <li>
        <b>-c</b> &lt;integer&gt;
        <p>&emsp;&emsp;Specifies the width (in characters) that the output will have. Default: 80</p>
    </li>
    <li>
        <b>-s</b> &lt;floating-point&gt;
        <p>&emsp;&emsp;Specifies the height scale factor. Default: 0.43</p>
    </li>
    <li>
        <b>-d</b>
        <p>&emsp;&emsp;Debug mode. Print additional information.</p>
    </li>
    <li>
        <b>-o</b> &lt;path&gt;
        <p>&emsp;&emsp;Set the output file to print instead of use standard output.</p>
    </li>
    <li>
        <b>-v</b>
        <p>&emsp;&emsp;Visualize also in standard output (if an output file was specified).</p>
    </li>
    <li>
        <b>-m</b>
        <p>&emsp;&emsp;Use more ascii characters (70). When no used are only 10.</p>
    </li>
</ul>

### Note:
[Magick++](https://github.com/ImageMagick/ImageMagick/tree/main/Magick%2B%2B) is required to compile this program.