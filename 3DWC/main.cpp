﻿
#include <WordsFrequency/WordsFrequency.h>
#include <WordConversion/WordConversion.h>
#include <CmdArguments/CmdArguments.h>

int main(int argc, char** argv)
{
    // initialize glog and gdiplus
    cl::App this_app(&argc, argv);
    if (true)
    {
        // read app id and key
        cl::WordsFrequency wf("config.json");

        char cntext[] =
            "我说道：“爸爸，你走吧。”他望车外看了看，说：“我买几个橘子去。你就在此地，不要走动。”"
            "我看那边月台的栅栏外有几个卖东西的等着顾客。走到那边月台，须穿过铁道，须跳下去又爬上去。父亲是一个胖子，走过去自然要费事些。"
            "我本来要去的，他不肯，只好让他去。我看见他戴着黑布小帽，穿着黑布大马褂12，深青布棉袍，蹒跚13地走到铁道边，慢慢探身下去，尚不大难。"
            "可是他穿过铁道，要爬上那边月台，就不容易了。他用两手攀着上面，两脚再向上缩；他肥胖的身子向左微倾，显出努力的样子。"
            "这时我看见他的背影，我的泪很快地流下来了。我赶紧拭干了泪。怕他看见，也怕别人看见。我再向外看时，他已抱了朱红的橘子往回走了。"
            "过铁道时，他先将橘子散放在地上，自己慢慢爬下，再抱起橘子走。到这边时，我赶紧去搀他。他和我走到车上，将橘子一股脑儿放在我的皮大衣上。"
            "于是扑扑衣上的泥土，心里很轻松似的。过一会儿说：“我走了，到那边来信！”我望着他走出去。他走了几步，回过头看见我，说：“进去吧，里边没人。”"
            "等他的背影混入来来往往的人里，再找不着了，我便进来坐下，我的眼泪又来了。";
        wf.sentence(cntext);
    }
    else
    {
        cl::CmdArguments args(argc, argv);
        for (auto& arg : args)
        {
            std::cout << arg.value() << std::endl;
        }
        cl::WordConversion cnv(30);
        auto rect = cnv.begin_conversion(L"橘子");
        for (int i = rect.GetTop(); i < rect.GetBottom(); i++)
        {
            for (int j = rect.GetLeft(); j < rect.GetRight(); j++)
            {
                std::cout << (cnv.visible(j, i) ? '+' : ' ');
            }
            std::cout << std::endl;

        }
    }

}