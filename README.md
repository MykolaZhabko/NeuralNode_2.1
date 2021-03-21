/\*! \mainpage My NEURONE

# About the project

Artificial intelligence representing a neuron which is able to recognize RED color.

- This project is a part of the 'C' programming language course.
- Teacher: Johan Dams https://www.purplealienplanet.com
- Student: Zhabko Mykola e2000594. http://www.cc.puv.fi/~e2000594/

# Introduction

<div style="width:90%">
<p>Welcome to the RED Color NEURONE console application.
My neuron is capable to study through the data I provide in the form of the 4 x 3 matrix, where each row is a RGB value, and 4 X 1 matrix where each row is a single number corresponding to the real output of RGB value row. After the teaching the Neurone will recognise the RED color, all other colors are just NOT RED (FALSE)</p> 
For instanse here is teaching data: <br>
</div>
<table style="width:20%" border="1px solid black" >
        <tr>
            <th style="color:red">RED (R)</th>
            <th style="color:green">GREEN (G)</th>
            <th style="color:blue">BLUE (B)</th>
            <th>Output (to)</th>
        </tr>
        <tr>
            <td>1</td>
            <td>0</td>
            <td>0</td>
            <td>1</td>
        </tr>
        <tr>
            <td>0</td>
            <td>1</td>
            <td>0.5</td>
            <td>0</td>
        </tr>
    </table>

#### Basic algorithm

<ol>
<li>Fill synaptic weights with random numbers in range -1..1</li>
<li>Create temporary output: Sygmoid(dot product RGB and synaptic weights (R*W1 + G*W2 + B*W3)) || \code temp_output[0] = sigmoid(dotProduct(&td[0][0], sw, 3));
temp_output[1] = sigmoid(dotProduct(&td[1][0], sw, 3));
temp_output[2] = sigmoid(dotProduct(&td[2][0], sw, 3));
temp_output[3] = sigmoid(dotProduct(&td[3][0], sw, 3)); \endcode</li>
<li>Calculate ERROR of the result: (Real output - Temporary output) * Sigmoid derivative of the Temporary output. 
\code for (int i = 0; i < 4; i++)
    {
      error[i] = (to[i] - temp_output[i]) * sigmoid_derivative(temp_output[i]);
    } \endcode</li>
<li>Calculate adjustment: 
\code  
adjustments[0] = dotProduct(&transpose[0][0], error, 4);
adjustments[1] = dotProduct(&transpose[1][0], error, 4);
adjustments[2] = dotProduct(&transpose[2][0], error, 4);
 \endcode</li>
<li>Add adjustments to the synaptic weights:
\code 
sw[0] = sw[0] + adjustments[0];
sw[1] = sw[1] + adjustments[1];
sw[2] = sw[2] + adjustments[2];
\endcode</li>
<li>Repeat from step 1 as many times as you like.</li>
</ol>

\image{inline} html Neurone.png "Basic sketch of the RGB Neurone"

\section install_sec Installation
The project contains SDL2 library functionality so if you want to use it as it is please instal the SDL2 to your mashine, see the link https://wiki.libsdl.org/Installation

- Download all sourse files from my GitHub repository https://github.com/MykolaZhabko/NeuralNode_2.1
- Run make: Just type "make" in the console open in repository with sourse files.
- Have fun!

# Applications User interface

\image{inline} html menu.png "Main menu"
<br><br>
\image{inline} html 1.png "synaptic weights"
<br><br>
\image{inline} html 2.png "Teaching of synaptic weights"
<br><br>
\image{inline} html 3.png "sAnalyse of red color"
<br><br>
\image{inline} html 4.png "Random red color picked by neurone"
<br><br>
\image{inline} html 5.png "Analyse of the image"
<br><br>
\image{inline} html 6.png "some info"
<br><br>
\image{inline} html 7.png "Settings for image analyse"
<br><br>

# Result of Image Analyse

Image before:<br><br>
\image{inline} html before.png "Image before analyse"

<br><br>
Image after Neurone analyse with probability of the RED color in 10%.

\image{inline} html after.png "Image after analyse"
