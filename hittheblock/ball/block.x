xof 0303txt 0032

// DirectX - from MilkShape3D

Frame blockFrame
{
    FrameTransformMatrix
    {
        1.000000,0.000000,0.000000,0.000000,
        0.000000,1.000000,0.000000,0.000000,
        0.000000,0.000000,1.000000,0.000000,
        0.000000,0.000000,0.000000,1.000000;;
    }

    Mesh blockMesh
    {
        14;
        -0.500000;-0.500000;-0.500000;,
        0.500000;-0.500000;-0.500000;,
        0.500000;0.500000;-0.500000;,
        -0.500000;0.500000;-0.500000;,
        0.500000;0.500000;0.500000;,
        -0.500000;0.500000;0.500000;,
        0.500000;-0.500000;0.500000;,
        -0.500000;-0.500000;0.500000;,
        0.500000;-0.500000;-0.500000;,
        -0.500000;-0.500000;-0.500000;,
        0.500000;-0.500000;0.500000;,
        0.500000;0.500000;0.500000;,
        -0.500000;-0.500000;0.500000;,
        -0.500000;0.500000;0.500000;;
        12;
        3;0,2,1;,
        3;0,3,2;,
        3;3,4,2;,
        3;3,5,4;,
        3;5,6,4;,
        3;5,7,6;,
        3;7,8,6;,
        3;7,9,8;,
        3;1,11,10;,
        3;1,2,11;,
        3;12,3,0;,
        3;12,13,3;;

        MeshNormals
        {
            6;
            0.000000;0.000000;-1.000000;,
            0.000000;1.000000;0.000000;,
            0.000000;0.000000;1.000000;,
            0.000000;-1.000000;0.000000;,
            1.000000;0.000000;0.000000;,
            -1.000000;0.000000;0.000000;;
            12;
            3;0,0,0;,
            3;0,0,0;,
            3;1,1,1;,
            3;1,1,1;,
            3;2,2,2;,
            3;2,2,2;,
            3;3,3,3;,
            3;3,3,3;,
            3;4,4,4;,
            3;4,4,4;,
            3;5,5,5;,
            3;5,5,5;;
        }

        MeshTextureCoords
        {
            14;
            0.375000;1.000000;,
            0.625000;1.000000;,
            0.625000;0.750000;,
            0.375000;0.750000;,
            0.625000;0.500000;,
            0.375000;0.500000;,
            0.625000;0.250000;,
            0.375000;0.250000;,
            0.625000;0.000000;,
            0.375000;0.000000;,
            0.875000;1.000000;,
            0.875000;0.750000;,
            0.125000;1.000000;,
            0.125000;0.750000;;
        }

        MeshMaterialList
        {
            1;
            12;
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0;

            Material blinn1
            {
                0.800000;0.800000;0.800000;1.000000;;
                0.000000;
                0.000000;0.000000;0.000000;;
                0.000000;0.000000;0.000000;;

                TextureFileName
                {
                    "block.png";
                }
            }
        }
    }
}