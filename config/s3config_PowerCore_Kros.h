// ProffieOS7 Config File
#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 3
#define NUM_BUTTONS 2
const unsigned int maxLedsPerStrip = 144;
#define VOLUME 2550
#define CLASH_THRESHOLD_G 4.5
#define AUDIO_CLASH_SUPPRESSION_LEVEL 5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define NO_REPEAT_RANDOM
#define KILL_OLD_PLAYERS
#define FILTER_CUTOFF_FREQUENCY 100
#define FILTER_ORDER 8
#define MOTION_TIMEOUT 60 * 15 * 1000
#define IDLE_OFF_TIME 60 * 15 * 1000
#define DISABLE_BASIC_PARSER_STYLES
#define DISABLE_DIAGNOSTIC_COMMANDS
#define BLADE_DETECT_PIN 17
#define SAVE_PRESET
#define COLOR_CHANGE_DIRECT
#define ENABLE_ALL_EDIT_OPTIONS
#define FETT263_EDIT_SETTINGS_MENU
#define FETT263_ENABLE_SPIN_MODE
#define FETT263_DISABLE_CHANGE_STYLE
#define FETT263_DISABLE_COPY_PRESET
#define FETT263_DISABLE_CHANGE_FONT
#define FETT263_LOCKUP_DELAY 200
#define FETT263_BM_CLASH_DETECT 8 
#define FETT263_FORCE_PUSH
#define FETT263_TWIST_ON
#define FETT263_TWIST_ON_NO_BM
#define FETT263_TWIST_OFF
//#define KEEP_SAVEFILES_WHEN_PROGRAMMING
#define FETT263_HOLD_BUTTON_OFF
#define FETT263_DISABLE_MULTI_BLAST
#define FETT263_DISABLE_MULTI_BLAST_TOGGLE
#endif

#ifdef CONFIG_PROP
#include "../props/saber_sabertrio_buttons.h"
//#include "../props/saber_fett263_buttons.h"
#endif

#ifdef CONFIG_PRESETS

Preset blade[] = {
  { "1-TEENSY_SF;common", "tracks/track_13.wav",

  /* copyright Fett263 Simple (Primary Blade) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#Simple
  OS6.7 v4.021
  Single Style
  Base Style: HumpFlicker Small (Single Color (80%)), Cyan, Prequel (NavajoWhite)

  Base Color: Rgb<0,255,255> (0)

  --Effects Included--
  Ignition Effect: SparkTip Ignition
  Retraction Effect: Standard Retraction
  Lockup Effect: Responsive Lockup, Begin Effect: Real Clash, End Effect: Full Blade Absorb
  LightningBlock Effect: Responsive Lightning Block
  Drag Effect: Intensity Sparking Drag
  Melt Effect: Responsive Melt
  Stab Effect: AudioFlicker Stab
  Blast Effect: Responsive Blast Fade (Large)
  Clash Effect: Flash on Clash (Full Blade)
  Battery Level: % Blade (Green to Red)
  */
  StylePtr<Layers<
    HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<26214>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>,60>,
    TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,
    TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>>>,TrFade<300>>,EFFECT_BLAST>,
    TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,
    LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<300>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
    TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

  /* copyright Fett263 Simple (Accent LED / PCB) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#Simple
  OS6.7 v4.021
  Single Style
  Base Style: HumpFlicker Large (Single Color (50%))

  Off Behavior: Fast Pulse Off-On

  Base Color: Rgb<0,255,255> (0)

  --Effects Included--
  Ignition Effect: Standard Ignition
  Retraction Effect: Instant
  */
  StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>,120>,InOutTrL<TrWipeX<IgnitionTime<0>>,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,2000>>>>(),

  /* copyright Fett263 Simple (Quillion / Secondary Blade) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#Simple
  OS6.6 v3.01
  Single Style
  Base Style: RandomFlicker (Single Color (50%)), Cyan, Prequel (NavajoWhite)

  --Effects Included--
  Ignition Effect: Standard Ignition
  Retraction Effect: Standard Retraction
  LightningBlock Effect: Responsive Lighting Block (LightCyan)
  */
  StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,255>>>>,ResponsiveLightningBlockL<LightCyan>,InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>>>(),
  "TeensySF"
  },

  { "2-SMOOTH_JEDI;common", "tracks/track_14.wav",

  /* copyright Fett263 Simple (Primary Blade) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#Simple
  OS6.7 v4.021
  Single Style
  Base Style: HumpFlicker Small (Single Color (80%)), Blue, Original (LemonChiffon)

  Base Color: Rgb<0,0,255> (0)

  --Effects Included--
  Ignition Effect: SparkTip Ignition
  Retraction Effect: Standard Retraction
  Lockup Effect: Responsive Lockup, Begin Effect: Real Clash, End Effect: Full Blade Absorb
  LightningBlock Effect: Responsive Lightning Block
  Drag Effect: Intensity Sparking Drag
  Melt Effect: Responsive Melt
  Stab Effect: AudioFlicker Stab
  Blast Effect: Responsive Blast Fade (Large)
  Clash Effect: Flash on Clash (Full Blade)
  Battery Level: % Blade (Green to Red)
  */
  StylePtr<Layers<
    HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<26214>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,60>,
    TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,
    TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>>>,TrFade<300>>,EFFECT_BLAST>,
    TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,
    LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<300>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
    TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

  /* copyright Fett263 Simple (Accent LED / PCB) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#Simple
  OS6.7 v4.021
  Single Style
  Base Style: HumpFlicker Large (Single Color (50%))

  Off Behavior: Fast Pulse Off-On

  Base Color: Rgb<0,0,255> (0)

  --Effects Included--
  Ignition Effect: Standard Ignition
  Retraction Effect: Instant
  */
  StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>,120>,InOutTrL<TrWipeX<IgnitionTime<0>>,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,2000>>>>(),

  /* copyright Fett263 Simple (Quillion / Secondary Blade) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#Simple
  OS6.6 v3.01
  Single Style
  Base Style: RandomFlicker (Single Color (50%)), Blue, Original (LemonChiffon)

  --Effects Included--
  Ignition Effect: Standard Ignition
  Retraction Effect: Standard Retraction
  LightningBlock Effect: Responsive Lighting Block (LightCyan)
  */
  StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,0,255>>>>,ResponsiveLightningBlockL<LightCyan>,InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>>>(), 
  "Smooth Jedi"
  },

  { "3-SMOOTH_GREY;common", "tracks/track_15.wav",

  /* copyright Fett263 Simple (Primary Blade) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#Simple
  OS6.6 v3.01
  Single Style
  Base Style: AudioFlicker (Single Color (75%)), Gold, Sequel (LightCyan)

  --Effects Included--
  Ignition Effect: SparkTip Ignition
  Retraction Effect: Standard Retraction
  Lockup Effect: Responsive Lockup (Absorb)
  LightningBlock Effect: Responsive Lightning Block
  Drag Effect: Intensity Sparking Drag
  Melt Effect: Intensity Melt
  Stab Effect: AudioFlicker Stab
  Blast Effect (Randomly Selected): Responsive Blast Fade (Medium), Responsive Blast Fade (Sound Based)
  Clash Effect: Flash on Clash (Full Blade)
  Battery Level: % Blade (Green to Red)
  */
  StylePtr<Layers<
    AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>,Mix<Int<24576>,Black,RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>>>,
    TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<191,255,255>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,
    MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<10000>>,RgbArg<BLAST_COLOR_ARG,Rgb<191,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<191,255,255>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<000>>,Scale<WavLen<>,Int<9000>,Int<13000>>>,RgbArg<BLAST_COLOR_ARG,Rgb<191,255,255>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<191,255,255>>>>,TrFade<300>>>,EFFECT_BLAST>,
    TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<191,255,255>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<191,255,255>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<191,255,255>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<191,255,255>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<191,255,255>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,
    LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<191,255,255>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<191,255,255>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
    TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

  /* copyright Fett263 Simple (Accent LED / PCB) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#Simple
  OS6.7 v4.021
  Single Style
  Base Style: HumpFlicker Large (Single Color (50%))

  Off Behavior: Fast Pulse Off-On

  Base Color: Rgb<180,130,0> (0)

  --Effects Included--
  Ignition Effect: Standard Ignition
  Retraction Effect: Instant
  */
  StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>>,120>,InOutTrL<TrWipeX<IgnitionTime<0>>,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>,2000>>>>(),

  /* copyright Fett263 Simple (Quillion / Secondary Blade) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#Simple
  OS6.6 v3.01
  Single Style
  Base Style: AudioFlicker (Single Color (75%)), Gold, Sequel (LightCyan)

  --Effects Included--
  Ignition Effect: Standard Ignition
  Retraction Effect: Standard Retraction
  LightningBlock Effect: Responsive Lighting Block (LightCyan)
  */
  StylePtr<Layers<AudioFlicker<RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>,Mix<Int<24576>,Black,RgbArg<BASE_COLOR_ARG,Rgb<180,130,0>>>>,ResponsiveLightningBlockL<LightCyan>,InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>>>(),
  "Smooth Grey"
  },

  { "4-SMOOTH_FUZZ;common", "tracks/track_16.wav",

  /* copyright Fett263 Simple (Primary Blade) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#Simple
  OS6.7 v4.021
  Single Style
  Base Style: HumpFlicker Small (Single Color (80%)),Purple, Prequel(NavajoWhite)

  Base Color: Rgb<115,15,240> (0)

  --Effects Included--
  Ignition Effect: SparkTip Ignition
  Retraction Effect: Standard Retraction
  Lockup Effect: Responsive Lockup, Begin Effect: Real Clash, End Effect: Full Blade Absorb
  LightningBlock Effect: Responsive Lightning Block
  Drag Effect: Intensity Sparking Drag
  Melt Effect: Responsive Melt
  Stab Effect: AudioFlicker Stab
  Blast Effect: Responsive Blast Fade (Large)
  Clash Effect: Flash on Clash (Full Blade)
  Battery Level: % Blade (Green to Red)
  */
  StylePtr<Layers<
    HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<115,15,240>>,Mix<Int<26214>,Black,RgbArg<BASE_COLOR_ARG,Rgb<115,15,240>>>,60>,
    TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,
    TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,187,108>>>>,TrFade<300>>,EFFECT_BLAST>,
    TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,187,108>>,TrFade<300>>,EFFECT_CLASH>,
    LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,187,108>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,
    LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,187,108>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,187,108>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<300>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<800>>,Black>,
    TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

  /* copyright Fett263 Simple (Accent LED / PCB) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#Simple
  OS6.7 v4.021
  Single Style
  Base Style: HumpFlicker Large (Single Color (50%))

  Off Behavior: Fast Pulse Off-On

  Base Color: Rgb<115,15,240> (0)

  --Effects Included--
  Ignition Effect: Standard Ignition
  Retraction Effect: Instant
  */
  StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<115,15,240>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<115,15,240>>>,120>,InOutTrL<TrWipeX<IgnitionTime<0>>,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<115,15,240>>,2000>>>>(),

  /* copyright Fett263 Simple (Quillion / Secondary Blade) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#Simple
  OS6.6 v3.01
  Single Style
  Base Style: RandomFlicker (Single Color (50%)), Purple, Prequel(NavajoWhite)


  --Effects Included--
  Ignition Effect: Standard Ignition
  Retraction Effect: Standard Retraction
  LightningBlock Effect: Responsive Lighting Block (LightCyan)
  */
  StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<115,15,240>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<115,15,240>>>>,ResponsiveLightningBlockL<LightCyan>,InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInX<RetractionTime<800>>,Black>>>(), 
  "Smooth Fuzz"
  },

  { "5-ROGUE_COMMANDER;common", "tracks/track_17.wav",

  /* copyright Fett263 FallenOrder (Primary Blade) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#FallenOrder
  OS6.6 v3.01
  Single Style
  Base Style: Fallen Order Ninth Sister, Red, Orignal (LemonChiffon)

  --Effects Included--
  Ignition Effect: Standard Ignition
  Retraction Effect: Standard Retraction
  Lockup Effect: Responsive Lockup (Absorb)
  LightningBlock Effect: Responsive Lightning Block
  Drag Effect: Intensity Sparking Drag
  Melt Effect: Intensity Melt
  Stab Effect: AudioFlicker Stab
  Blast Effect (Randomly Selected): Responsive Blast Fade (Random), Responsive Blast Fade (Large)
  Clash Effect: Flash on Clash (Full Blade)
  Battery Level: % Blade (Green to Red)
  RetractionTime : 800
  */
  StylePtr<Layers<
    Stripes<18000,-1600,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,
    Stripes<9000,-900,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>>>,
    TransitionEffectL<TrConcat<TrExtendX<WavLen<>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,
    MultiTransitionEffectL<TrRandom<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Scale<EffectRandomF<EFFECT_BLAST>,Int<9000>,Int<13000>>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>>>,TrFade<300>>,TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>>>,TrFade<300>>>,EFFECT_BLAST>,
    TransitionEffectL<TrConcat<TrExtend<30,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,TrFade<300>>,EFFECT_CLASH>,
    LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,
    LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrConcat<TrExtend<4000,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,LockupTrL<AlphaL<Remap<Scale<RampF,Int<65536>,Int<0>>,StaticFire<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,Mix<TwistAngle<>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>,RotateColorsX<Int<3000>,Mix<Int<12000>,Black,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>>,0,3,5,3000,10>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrExtend<4000,TrFade<300>>,AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<4000>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInX<RetractionTime<800>>,Black>,
    TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

  /* copyright Fett263 Simple (Accent LED / PCB) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#Simple
  OS6.7 v4.021
  Single Style
  Base Style: HumpFlicker Large (Single Color (50%))

  Off Behavior: Fast Pulse Off-On

  Base Color: Rgb<255,0,0> (0)

  --Effects Included--
  Ignition Effect: Standard Ignition
  Retraction Effect: Instant
  */
  StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>,120>,InOutTrL<TrWipeX<IgnitionTime<0>>,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,2000>>>>(),

  /* copyright Fett263 FallenOrder (Quillion / Secondary Blade) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#FallenOrder
  OS6.6 v3.01
  Single Style
  Base Style: Fallen Order Ninth Sister, Red, Orignal (LemonChiffon)

  --Effects Included--
  Ignition Effect: Standard Ignition
  Retraction Effect: Standard Retraction
  LightningBlock Effect: Responsive Lighting Block (LightCyan)
  */
  StylePtr<Layers<Stripes<18000,-1600,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<16384>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>,RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,
  Stripes<9000,-900,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>,Mix<Int<7710>,Black,RgbArg<BASE_COLOR_ARG,Rgb<255,0,0>>>>>>,ResponsiveLightningBlockL<LightCyan>,InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInX<RetractionTime<800>>,Black>>>(),
  "Rogue Commander"
  },

  { "6-TYTHONIAN_CRYSTAL;common", "tracks/track_18.wav",

  /* copyright Fett263 Simple (Primary Blade) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#Simple
  OS6.7 v4.021
  Single Style
  Base Style: HumpFlicker Small (Single Color (80%)), Green, Original (LemonChiffon)

  Base Color: Rgb<0,255,0> (0)

  --Effects Included--
  Ignition Effect: SparkTip Ignition
  Retraction Effect: Standard Retraction
  Lockup Effect: Responsive Lockup, Begin Effect: Real Clash, End Effect: Full Blade Absorb
  LightningBlock Effect: Responsive Lightning Block
  Drag Effect: Intensity Sparking Drag
  Melt Effect: Responsive Melt
  Stab Effect: AudioFlicker Stab
  Blast Effect: Responsive Blast Fade (Large)
  Clash Effect: Flash on Clash (Full Blade)
  Battery Level: % Blade (Green to Red)
  */
  StylePtr<Layers<
    HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<26214>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,60>,
    TransitionEffectL<TrConcat<TrJoin<TrDelayX<WavLen<>>,TrWipeIn<200>>,AlphaL<AudioFlickerL<RgbArg<STAB_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<2000>>>,TrWipe<200>>,EFFECT_STAB>,
    TransitionEffectL<TrConcat<TrInstant,AlphaMixL<Bump<Scale<BladeAngle<>,Int<28000>,Int<8000>>,Int<14000>>,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>,Mix<Int<16384>,Black,RgbArg<BLAST_COLOR_ARG,Rgb<255,244,157>>>>,TrFade<300>>,EFFECT_BLAST>,
    TransitionEffectL<TrConcat<TrJoin<TrDelay<30>,TrInstant>,RgbArg<CLASH_COLOR_ARG,Rgb<255,244,157>>,TrFade<300>>,EFFECT_CLASH>,LockupTrL<AlphaMixL<Bump<Scale<BladeAngle<>,Scale<BladeAngle<0,16000>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<-12000>>,Sum<IntArg<LOCKUP_POSITION_ARG,16000>,Int<10000>>>,Scale<SwingSpeed<100>,Int<14000>,Int<18000>>>>,AudioFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>>,BrownNoiseFlickerL<RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,Int<200>>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,TrConcat<TrInstant,RgbArg<LOCKUP_COLOR_ARG,Rgb<255,244,157>>,TrFade<400>>,SaberBase::LOCKUP_NORMAL>,
    ResponsiveLightningBlockL<Strobe<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,AudioFlicker<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Blue>,50,1>,TrConcat<TrInstant,AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Bump<Int<12000>,Int<18000>>>,TrFade<200>>,TrConcat<TrInstant,HumpFlickerL<AlphaL<RgbArg<LB_COLOR_ARG,Rgb<191,255,255>>,Int<16000>>,30>,TrSmoothFade<600>>>,
    LockupTrL<AlphaL<RandomPerLEDFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrConcat<TrJoin<TrDelay<4000>,TrWipeIn<200>>,AlphaL<BrownNoiseFlickerL<RgbArg<DRAG_COLOR_ARG,Rgb<255,244,157>>,Int<300>>,SmoothStep<IntArg<DRAG_SIZE_ARG,30000>,Int<3000>>>,TrFade<4000>>,TrFade<300>,SaberBase::LOCKUP_DRAG>,
    LockupTrL<AlphaL<Mix<TwistAngle<>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,RotateColorsX<Int<3000>,RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrConcat<TrWipeIn<100>,AlphaL<RgbArg<STAB_COLOR_ARG,Rgb<255,24,0>>,SmoothStep<IntArg<MELT_SIZE_ARG,30000>,Int<4000>>>,TrFade<300>>,TrWipe<200>,SaberBase::LOCKUP_MELT>,
    InOutTrL<TrWipeSparkTipX<RgbArg<IGNITION_COLOR_ARG,Rgb<255,255,255>>,IgnitionTime<300>>,TrWipeInX<RetractionTime<0>>,Black>,
    TransitionEffectL<TrConcat<TrJoin<TrDelay<2000>,TrWipe<1000>>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-10>>>,TrWipeIn<1000>>,EFFECT_BATTERY_LEVEL>,
    TransitionEffectL<TrConcat<TrExtend<2000,TrWipe<0>>,AlphaL<Mix<VolumeLevel,Red,Green>,SmoothStep<VolumeLevel,Int<-10>>>,TrSmoothFade<300>>,EFFECT_VOLUME_LEVEL>>>(),

  /* copyright Fett263 Simple (Accent LED / PCB) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#Simple
  OS6.7 v4.021
  Single Style
  Base Style: HumpFlicker Large (Single Color (50%))

  Off Behavior: Fast Pulse Off-On

  Base Color: Rgb<0,255,0> (0)

  --Effects Included--
  Ignition Effect: Standard Ignition
  Retraction Effect: Instant
  */
  StylePtr<Layers<HumpFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>,120>,InOutTrL<TrWipeX<IgnitionTime<0>>,TrInstant,Pulsing<Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,2000>>>>(),

  /* copyright Fett263 Simple (Quillion / Secondary Blade) OS6 Style
  https://fett263.com/fett263-proffieOS6-style-library.html#Simple
  OS6.6 v3.01
  Single Style
  Base Style: RandomFlicker (Single Color (50%)), Green, Original (LemonChiffon)

  --Effects Included--
  Ignition Effect: Standard Ignition
  Retraction Effect: Standard Retraction
  LightningBlock Effect: Responsive Lighting Block (LightCyan)
  */
  StylePtr<Layers<RandomFlicker<RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>,Mix<Int<16448>,Black,RgbArg<BASE_COLOR_ARG,Rgb<0,255,0>>>>,ResponsiveLightningBlockL<LightCyan>,InOutTrL<TrWipeX<IgnitionTime<300>>,TrWipeInX<RetractionTime<800>>,Black>>>(),
  "Tythonian Crystal"
  },

};

BladeConfig blades[] = {
  { 0, 
  WS281XBladePtr<133, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),
  SubBlade(0, 0, WS281XBladePtr<20, blade4Pin, Color8::GRB, PowerPINS<bladePowerPin4,bladePowerPin5, bladePowerPin1> >()),
  SubBlade(1,19, NULL),
  CONFIGARRAY(blade)
  },
};
#endif

#ifdef CONFIG_BUTTONS
  Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
  Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif