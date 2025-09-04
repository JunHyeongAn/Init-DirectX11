float4x4 g_World;
float4x4 g_WVP;

struct VS_IN
{
    float3 vPos : POSITION;
    float4 vColor : COLOR0;
};

struct VS_OUT
{
    float4 vPos : SV_Position;
    float4 vColor : COLOR0;
};

VS_OUT VS_MAIN( VS_IN In )
{
    VS_OUT vsOut;
    
    vsOut.vPos = mul(float4(In.vPos, 1.f), g_WVP);
    vsOut.vColor = In.vColor;
    
    return vsOut;
}

struct PS_IN
{
    float4 vPos : SV_Position;
    float4 vColor : COLOR0;
};

struct PS_OUT
{
    float4 vColor : SV_TARGET0;
};

PS_OUT PS_MAIN(PS_IN In)
{
    PS_OUT psOut;
    
    psOut.vColor = float4(1, 1, 0, 1);
    
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