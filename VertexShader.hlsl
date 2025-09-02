struct VS_IN
{
    float3 vPos : POSITION;
    float4 vColor : COLOR;
};

struct VS_OUT
{
    float4 vPos : POSITION;
    float4 vColor : COLOR;
};

VS_OUT VS_MAIN( VS_IN In )
{
    VS_OUT vsOut;
    
    vsOut.vPos = float4(In.vPos, 1.f);
    
    return vsOut;
}

struct PS_IN
{
    float4 vPos : POSITION;
    float4 vColor : COLOR;
};

struct PS_OUT
{
    vector vColor : SV_TARGET0;
};

PS_OUT PS_MAIN(PS_IN In)
{
    PS_OUT psOut;
    
    psOut.vColor.rg = 1.f;
    psOut.vColor.b = 0.f;
    psOut.vColor.a = 1.f;
    
    return psOut;
}

technique11 DefaultTechnique
{
    pass DefaultPass
    {
        VertexShader = compile vs_5_0 VS_MAIN();
        PixelShader = compile ps_5_0 PS_MAIN();
    }
}