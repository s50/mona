//ルパンタイトル
#define MAX_TITLE   155

const char Titles[][MAX_TITLE] = {
    "ルパン三世颯爽登場",
    "リオの夕陽に咲く札束",
    "ヒトラーの遺産",
    "ネッシーの唄が聞こえる",
    "金塊の運び方教えます",
    "ピサの斜塔は立っているか",
    "ツタンカーメン三千年の呪い",
    "ベネチア超特急",
    "浮世絵ブルースはいかが",
    "ファイルＭ１２３を盗め",
    "モナコＧＰにかけろ",
    "大統領への贈り物",
    "サンフランシスコ大追跡",
    "カリブ海の大冒険",
    "名探偵空を行く",
    "二つの顔のルパン",
    "オイルダラーを狙え",
    "ブラックパンサー",
    "十年金庫は破れるか！？",
    "追いつめられたルパン",
    "五右ヱ門の復讐",
    "謎の女人館を探れ",
    "第４次元の魔女",
    "怪盗ねずみ小僧現わる",
    "必殺鉄トカゲ見参",
    "バラとピストル",
    "シンデレラの切手はどこへ行った",
    "女刑事メロン",
    "モロッコの風は熱く",
    "電撃ハトポッポ作戦",
    "白夜に向かって撃て",
    "ルパンは二度死ぬ",
    "オリオンの王冠は誰のもの",
    "吸血鬼になったルパン",
    "ゴリラギャングをやっつけろ",
    "月影城の秘密をあばけ",
    "ジンギスカンの埋蔵金",
    "ＩＣＰＯの甘い罠",
    "香港の空港にダイヤは消えた",
    "ミサイルジャック作戦",
    "かぐや姫の宝を探せ",
    "花嫁になったルパン",
    "北京原人の骨はどこに",
    "消えた特別装甲車",
    "殺しはワインの匂い",
    "ルパンお高く売ります",
    "女王陛下のずっこけ警部",
    "非常ベルにルパンは笑う",
    "可愛い女には毒がある",
    "私が愛したルパン（前編）",
    "私が愛したルパン（後編）",
    "エマニエルは天使のささやき",
    "狂気のファントマ・マークⅢ",
    "半七刑事十年目の約束",
    "花吹雪・謎の五人衆（前編）",
    "花吹雪・謎の五人衆（後編）",
    "コンピューターかルパンか",
    "国境は別れの顔",
    "マダムＸの不思議な世界",
    "インドに自殺の花が咲く",
    "空飛ぶ斬鉄剣",
    "ルパンを呼ぶ悪魔の鐘の音",
    "罠には罠を",
    "クリスマスは女神の手に",
    "ルパンの敵はルパン",
    "射殺命令！",
    "ルパンの大西遊記",
    "カジノ島逆転また逆転",
    "とっつあんの惚れた女",
    "クラシック泥棒と九官鳥",
    "ルパン対新選組",
    "花も嵐も泥棒レース",
    "スケートボード殺人事件",
    "恐怖のカメレオン人間",
    "不二子に花嫁衣装は似合わない",
    "シェークスピアを知ってるかい",
    "星占いでルパンを逮捕",
    "ロボットの瞳にダイヤが光る",
    "ルパン葬送曲",
    "最後の差し入れはカップラーメン",
    "不二子！男はつらいぜ",
    "とっつあん人質救出作戦",
    "ルパンの大西部劇",
    "復讐はルパンにまかせろ",
    "ＩＣＰＯ堯指令",
    "謎の夜光仮面現わる",
    "悪魔がルパンを招くとき",
    "ルパンの南極北極大冒険",
    "ドロボウ交響曲を鳴らせ",
    "悪い奴ほど大悪党",
    "時を駆ける少女",
    "マダムと泥棒四重奏",
    "万里の長城インベーダー作戦",
    "ルパン対スーパーマン",
    "幽霊船より愛をこめて",
    "ルパンのお料理天国",
    "ルパン一世の秘密を探せ",
    "父っあんのいない日",
    "荒野に散ったコンバットマグナム",
    "名画強奪ウルトラ大作戦",
    "ベルサイユは愛に燃えた",
    "ルパンはシャネルがお好き",
    "狼は天使を見た",
    "もっとも危険な黄金ベッド",
    "怪奇鬼首島に女が消えた",
    "君はネコ、ボクはカツオ節",
    "結婚指輪は呪いの罠",
    "哀しみの斬鉄剣",
    "ルパン史上最大の苦戦",
    "激写これが不二子だ",
    "インベーダー金庫は開いたか",
    "五右ヱ門危機一髪",
    "作戦名は忠臣蔵",
    "迷画最初の晩餐                の秘密  ",
    "モナリザは２度笑う",
    "１０８つの鐘は鳴ったか",
    "チューインガム変装作戦",
    "南十字星がダイヤに見えた",
    "ルパンを殺したルパン",
    "フランケンシュタインルパンを襲う",
    "オレの爺さんが残した宝物",
    "珍発見ナポレオンの財宝",
    "泥棒はパリで",
    "１９９９年ポップコーンの旅",
    "オイルダラーの大謀略",
    "地獄へルパンを道づれ",
    "直撃！デッドボール作戦",
    "老婆とルパンの泥棒合戦",
    "次元に男心の優しさを見た",
    "ルパン対奇人二面相",
    "二人五右ヱ門斬鉄剣の謎",
    "霊山ヒマラヤの泥棒教団",
    "熱いお宝に手を出すな",
    "ルパン逮捕頂上作戦",
    "毒薬と魔術とルパン三世",
    "ゴールドバタフライの復讐",
    "華麗なるチームプレイ作戦",
    "ポンペイの秘宝と毒蛇",
    "ルパンの全てを盗め",
    "狼は走れ豚は転がれ！",
    "１９８０モスクワ黙示録",
    "グランドレース消えた大本命",
    "マイアミ銀行襲撃記念日",
    "不二子危機一髪救出作戦",
    "死の翼アルバトロス",
    "ルパン華麗なる敗北",
    "白夜に消えた人魚",
    "ターゲットは５５５Ｍ",
    "ベールをはいだメッカの秘宝",
    "ピアノ交響曲「 動 物 園 」 ",
    "ルパン逮捕ハイウェイ作戦",
    "次元と帽子と拳銃と",
    "神様のくれた札束",
    "ヘクサゴンの大いなる遺産",
    "さらば愛しきルパンよ"
};

