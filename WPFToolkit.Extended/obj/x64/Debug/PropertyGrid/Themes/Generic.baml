   M S B A M L   `   `   `  ����N  JWPFToolkit.Extended, Version=1.4.0.0, Culture=neutral, PublicKeyToken=nulla5clr-namespace:Microsoft.Windows.Controls.PropertyGrid'Microsoft.Windows.Controls.PropertyGrid  5      g8clr-namespace:Microsoft.Windows.Controls.Core.Converters*Microsoft.Windows.Controls.Core.Converters  5      w@clr-namespace:Microsoft.Windows.Controls.PropertyGrid.Converters2Microsoft.Windows.Controls.PropertyGrid.Converters  5      e7clr-namespace:Microsoft.Windows.Controls.Core.Utilities)Microsoft.Windows.Controls.Core.Utilities  5      s>clr-namespace:Microsoft.Windows.Controls.PropertyGrid.Commands0Microsoft.Windows.Controls.PropertyGrid.Commands  5      \ XPresentationFramework, Version=3.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=3.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=3.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35    BooleanToVisibilityConverterE    ?Microsoft.Windows.Controls.Core.Converters.InverseBoolConverter  InverseBoolConverterX   RMicrosoft.Windows.Controls.PropertyGrid.Converters.ValueSourceToImagePathConverter # ValueSourceToImagePathConverterV  PMicrosoft.Windows.Controls.PropertyGrid.Converters.ValueSourceToToolTipConverter ! ValueSourceToToolTipConverter  MouseOverBorderBrush  �� Color  MouseOverBackgroundBrush �� 
StartPoint �� EndPoint � Offset � Color  CheckedBorderBrush  CheckedBackgroundBrush  PressedBorderBrush 	 PressedBackgroundBrush 
 OptionsToggleButtonStyle �� 
TargetType �� Property �� Value �� 
TargetType	 J� SnapsToDevicePixels
 ��Name �� CornerRadius �� Padding ��Name ��Name �� BitmapScalingMode �� Triggers P� Property P� Value �� 
TargetName ]� 
Conditions �� Property �� Value  
GlyphBrush  ExpanderToggleButton ��Name F�Name J� RenderTransformOrigin �� ScaleX �� ScaleY �� AngleX �� AngleY �� Angle T� X  T� Y  ExpanderStyle! � RowDefinitions" ��Name# � ColumnDefinitions$ � OverridesDefaultStyle% d� 	IsChecked& �� Path' �� Mode( �� RelativeSourceB   <Microsoft.Windows.Controls.PropertyGrid.PropertyCategoryItem)   Category* 9� 
IsExpanded:   4Microsoft.Windows.Controls.PropertyGrid.PropertyItem+ � 	Resources  Key, m� Command  ContextMenu- � ContextMenu. �� 	Placement/ �� AncestorType:   4Microsoft.Windows.Controls.PropertyGrid.PropertyGridD   >Microsoft.Windows.Controls.Core.Utilities.ContextMenuUtilities!0   OpenOnMouseLeftButtonClick1 ��Name2 �� 	Converter3 � ToolTip4   Editor5 �� Value6 �� Binding7 �� Orientation8   SelectedObjectTypeName9   SelectedObjectName: J� Opacity; n�Name< � Cursor= �� Padding�� 5      D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    8x,http://schemas.microsoft.com/winfx/2006/xaml    5      ?local5clr-namespace:Microsoft.Windows.Controls.PropertyGrid  5      G
converters8clr-namespace:Microsoft.Windows.Controls.Core.Converters  5      QpgConverters@clr-namespace:Microsoft.Windows.Controls.PropertyGrid.Converters  5      E	utilities7clr-namespace:Microsoft.Windows.Controls.Core.Utilities  5      Kcommands>clr-namespace:Microsoft.Windows.Controls.PropertyGrid.Commands  5      %.  &	        &	      &	 &     &	 9     &	 L     &	 o     &	 �    &	 �    &	 �    &		     &	
 {    7  7  7  7  7 	 7  &	     &	 )    7  7  &	 o    7  '  �    7  '  �    7  7  7  7  '  -#    7 
 7 
 7  7   7   �� 5      6#      5      6&     5      63     5      61   �� 5      $  	#FFFFB700��63   �� 5      $	 0,0&�6;   $	 0,1&�6L   .��5   
   � $ 0Q�6   $ 	#FFFEFBF4��6"   � 5   
   $
 0.19Q�6   $ 	#FFFDE7CE��6%   � 5   
   $
 0.39Q�6   $ 	#FFFDDEB8��6%   � 5   
   $
 0.39Q�6   $ 	#FFFFCE6B��6%   � 5   
   $
 0.79Q�6   $ 	#FFFFDE9A��6%   � 5   
   $ 1Q�6   $ 	#FFFFEBAA��6"   5      �� 5      $  	#FFC29B29��61   �� 5      $	 0,0&�69   $	 0,1&�6J   .��5   
   � $ 0Q�6   $ 	#FFFFDCA0��6"   � 5   
   $
 0.18Q�6   $ 	#FFFFD692��6%   � 5    
   $
 0.39Q�6   $ 	#FFFFC45D��6%   � 5!   
   $ 1Q�6   $ 	#FFFFD178��6"   5"      �� 5$      $  	#FFC29B29��61   �� 5%      $	 0,0&�69   $	 0,1&�6J   .��5&   
   � $ 0Q�6   $ 	#FFE3C085��6"   � 5'   
   $
 0.19Q�6   $ 	#FFF4CC89��6%   � 5(   
   $
 0.36Q�6   $ 	#FFF5C777��6%   � 5)   
   $
 0.36Q�6   $ 	#FFF5BB56��6%   � 5*   
   $
 0.79Q�6   $ 	#FFF4CE9A��6%   � 5+   
   $ 1Q�6   $ 	#FFF3E28D��6"   5,      �� 5.      " 	�6-   .�5/   
   ��  � ��
 ���� 6'   �� 50   
    � ��
 ���� 6(   �� 51   
    � ��$ 1q�6,   �� 52   
    �@�FocusVisualStyle 6-   Z� �� 53   
    � ��$ 22��6#   �� 54   
    � ��$ Center=�67   �� 55   
    �@^�InitialShowDelay$	 900��6<   �� 56   
    �@^�ShowDuration$ 20000��68   �� 57   
    �@^�BetweenShowDelay$ 0��6<   �� 58   
    � �� 59      �� 5:      " 	�6"   .R�5;      � 	 . .+�5<      �� $
 OuterBorder��6!   #��z��66   #��z��6b   #��z��6�   $ 2��6�   �� 5=      $
 MiddleBorder��6!   
������ #��z��6Q   
������ $ 2��6�   ._�5>      �� $
 InnerBorder��6%   
������ #��z��6T   
������ $ 2��6�   # z��6�   ._�5?   "   �� $ 
StackPanel��6-   #��z��6A   .+�5@   &   �� $ Content��67   #��z��6H   $��1q�6l   $ NearestNeighbor=�5A   ,   $��Center=�5B   ,   #��z��5C   ,   5D   #   5E      5F      5G       5H      P� 5I       �@J�IsMouseOver . . �5J      �� $ OuterBorder��6;   8    � ��6T   �� 5K      $ OuterBorder��6<   8   � ��6U   �� 5L      $ InnerBorder��6<    � �� �	#80FFFFFF6U   5M      P� 5O       � {� .  . �5P      �� $ Content��68    �@J�Opacity$	 0.5Q�6M   �� 5Q      $ OuterBorder��6G    � �� �	#FF9E9E9E6`   5R      P� 5T       �@d�	IsChecked$
 TrueY�67   . �5U      �� $ OuterBorder��6;   8   � ��6T   �� 5V      $ OuterBorder��6<   8   � ��6U   �� 5W      $ InnerBorder��6<    � �� 5X   "   �� 5Y   &   $	 0,1&�6:   $	 0,0&�6I   .��5Z   *   � $ 	#FFE7CBAD��67   $ 0Q�6I   � 5[   *   $ 	#FFF7D7B5��67   $	 0.1Q�6I   � 5\   *   $ 	#FFFFD38C��67   $
 0.36Q�6I   � 5]   *   $ 	#FFFFC75A��67   $
 0.36Q�6I   � 5^   *   $ 	#FFFFEFA5��67   $ 1Q�6I   5_   '   5a      5b      P� 5d       � �� . . �5e      �� $ OuterBorder��6;   8   � ��6T   �� 5f      $ OuterBorder��6<   8   � ��6U   �� 5g      $ InnerBorder��6<    � ��
 ���� 6U   5h      ]� 5j       5k      �� 5l   "    �@d�	IsChecked$
 TrueY�6A   �� 5m   "    �@J�IsMouseOver . 6C   ./�5o      �� $ MiddleBorder��6;    � �� 5p   "   �� 5q   &   $	 0,1&�6:   $	 0,0&�6I   .��5r   *   � $ 	#40FFFEFE��67   $ 0Q�6I   � 5s   *   $ 	#40FFFEFE��67   $
 0.39Q�6I   � 5t   *   $ 	#20FFCE68��67   $
 0.39Q�6I   � 5u   *   $ 	#20FFCE68��67   $
 0.69Q�6I   � 5v   *   $ 	#10FFFFFF��67   $ 1Q�6I   5w   '   5y      5z      5|      5~      5      �� 5�      $  	#FF31347C��6)   �� 5�      " d�63   .R�5�   
   � .+�5�      �� $ 	Rectangle��6)   $��0,0,0,0q�6   
������ 6<   F� 5�      $ Up_Arrow��60   $��Center=�6   $��Center=�6B   8��  "����        � 	=  	= � z     	$ 0.5,0.5&�6�   z�5�      V� 5�      .~�5�      �� $ 1Q�6)   $ 1Q�64   �� 5�      $ 0Q�6(   $ 0Q�63   �� 5�      $	 -90Q�6*   T� 5�      $ 0Q�6-   $  0Q�63   5�      5�      F� 5�      $ 
Down_Arrow��6G   $y�	Collapsed=�6   $��Center=�6*   $��Center=�6[   8�� "����     	= � 	=     � z  	= 	$ 0.5,0.5&�6�   z�5�      V� 5�      .~�5�      �� $ 1Q�6)   $ 1Q�64   �� 5�      $ 0Q�6(   $ 0Q�63   �� 5�      $	 135Q�6*   T� 5�      $ 0Q�6-   $  0Q�63   5�      5�      5�       5�   
   P� 5�       �@d�	IsChecked$
 trueY�6+   . �5�      �� $ 
Down_Arrow��6?    � y�$ Visible=�6/   6?   �� 5�      $ Up_Arrow��6A    � y�$ 	Collapsed=�6/   6A   �� 5�      $ 
Down_Arrow��60    �@J�OpacityMask �	#FF0000006H   5�      5�      �� 5�      " 9�6"   .�5�   
   ��  � ��$ 0q�6$   �� 5�   
    � �� �	#FFF0F0F06'   �� 5�   
    � �� 5�      �� 5�      " 9�6"   .R�5�      � ! 5�      �� 5�      $
��Auto �6,   �� 5�      $" 
ContentRow��67   $��* �6,   67   .+�5�      �� $
 Border��6!   #��z��61   ���	#FFF0F0F0._�5�      � # 5�   "   �� 5�   &   $��20 �67   �� 5�   &   $��* �67   .+�5�   "   d� 8��  $ . % 6`   �� $& 
IsExpanded�$' TwoWay=�( �� *TemplatedParent+6�   �� 5�   "   $��1��63   $��1q�6C   ��. $��Header��6i   $
��Bold"�6�   5�      5�      �� 5�      $
 
ExpandSite��6E   $y�	Collapsed=�6!   $��1��68   ���	#FFF0F0F0$ 10 0 0 0q�6p   ._�5�      �� ���#FFFFFF$��0q�6:   $��0q�6N   $ 0q�6Y   $��Stretch=�6e   $��Stretch=�6�   ._�5�   "   �� #��z��63   #��z��6v   #��z��6�   |�.  6�   5�      5�      5�       5�      P� 5�       �@9�
IsExpanded . . �5�      �� $ 
ExpandSite��6K    � y�$ Visible=�6;   6K   5�      5�      5�      5�      �� 5�      "  6   .�5�   
   ��  � �� 5�      �� 5�      "  6"   .R�5�      �� #��z��6   #��z��5�      #��z��5�      ._�5�      9� #��z) 6#   8��  * . .��5�      �� ��6+   �� *
Properties+( �� *TemplatedParent+5�      5�      5�      5�      5�      �� 5�      "  6   .�5�   
   ��  � �� �	#FFF0F0F06(   �� 5�   
    � ��$ 1q�6,   �� 5�   
    � |� . 6&   �� 5�   
    � �� .  6&   �� 5�   
    � �� 5�      �� 5�      "  6"   + 5�      ���� 5�      ContextMenu .@�5�      m� $��Reset Value��6'   $., (commands:PropertyItemCommands.ResetValue��6<   5�      5�      .R�5�      �� 
�������8-   $. Bottom=�6[   ._�5�      � $��Center=�6   $��Stretch=�6:   # 5�      �� 5�   "   ��63   �� *NameColumnWidth+( �� *FindAncestor+"/  �� 5�   "   $��* �63   .+�5�      �� $
 	PART_Name��6S   $	��0.5q�6%   ���	#FFF0F0F0._�5�   "   � $��7,2,2,2q�6'   # 5�   &   �� 5�   *   $��* �6;   �� 5�   *   $
��Auto �6;   .+�5�   &   �� $��Stretch=�6w   $��CharacterEllipsis=�6�   ��60   �� *Name+( �� *TemplatedParent+6�   � 5�   &   $��1��6+   $��Right=�6;   $��5,0,5,0q�6W   0 . 8-  .+�5�   *   �� $1 _optionsImage��60   $��11��6G   $��11��6R   ��5�   0   �� *ValueSource+( �� *TemplatedParent+82  3 5�   0   �� *ValueSource+( �� *TemplatedParent+82  5�   '   5   #   5     �� 5     $
 PART_Editor��6S   $	��0.5q�6%   ���	#FFF0F0F0$��1��6i   
������ ._�5  "   �� #��z4 61   $��Center=�6T   |�.  ��.  6�   5     5     5      5     �� 5	     $
5 True��6l   6 6&   �� *IsDataBound+( �� *Self+.a�5
     �� $ _optionsImage��6%    � ��$G A/WPFToolkit.Extended;component/PropertyGrid/Images/Database11.png��6R   �� 5     $ _optionsImage��6%    �@�ToolTip$ Databinding��6S   5     �� 5     $
5 True��6r   6 6&   �� *IsDynamicResource+( �� *Self+.a�5     �� $ _optionsImage��6%    � ��$G A/WPFToolkit.Extended;component/PropertyGrid/Images/Resource11.png��6R   �� 5     $ _optionsImage��6%    �@�ToolTip$ Resource��6S   5     �� 5     $
5 True��6s   6 6&   �� *HasResourceApplied+( �� *Self+.a�5     �� $ _optionsImage��6%    � ��$G A/WPFToolkit.Extended;component/PropertyGrid/Images/Resource11.png��6R   �� 5     $ _optionsImage��6%    �@�ToolTip$ Resource��6S   5     P� 5      �@J�IsMouseOver . . �5     �� $ 	PART_Name��6%    � �� �#CED4DF6R   5     P� 5      �@ 
IsSelected . . �5     �� $ 	PART_Name��6%    � �� �#43577B6R   �� 5     $ 	PART_Name��6%    � ��
 �����6^   5     5     5     5      �� 5"     "  6   .�5#  
   ��  � �� �#CED4DF6'   �� 5$  
    � �� �#43577B6(   �� 5%  
    � ��$ 1q�6,   �� 5&  
    � �� 5'     �� 5(     "  6"   .R�5)     �� #��z��6   #��z��6G   #��z��6s   ._�5*     � ! 5+     �� 5,  "   $
��Auto �60   �� 5-  "   $
��Auto �60   �� 5.  "   �� 5/  "   $��5 �60   �� 50  "   $
��Auto �60   .+�53     �� $7 
Horizontal=�6)   $��6,2,0,4q�6B   .+�54  "   �� #��z8 6,   $
��Bold"�6\   �� 55  "   #��z9 6,   $��5,0,0,0q�6X   56     � 58     $��1��6#   $��4,0,4,4q�60   # 59  "   �� 5:  &   $
��Auto �67   �� 5;  &   $��* �67   .+�5=  "   � ���#BCC7D8$��4q�6<   .+�5>  &   �� $7 
Horizontal=�61   $��1q�6J   .+�5?  *   	� $��Center=�6�   8��  $3 Categorized��5@  h   % 5?  6   �� *IsCategorized+( �� *TemplatedParent+.��5A  .   �� $I��C/WPFToolkit.Extended;component/PropertyGrid/Images/Categorize16.png��64   $��16��6�   $��16��6�   5B  +   	� 5C  *   $��Center=�6�   8�� $3 Alphabetical��5D  h   % 5C  6   �� *IsCategorized+( �� *TemplatedParent+82  $' OneWay=�.��5E  .   �� $L��F/WPFToolkit.Extended;component/PropertyGrid/Images/SortAscending16.png��64   $��16��6�   $��16��6�   5F  +   5G  '   5H  #   �� 5I  "   $��1��6*   $��Not Implemented��6:   $��4q�6Q   $: .5Q�6\   $y�Hidden=�6i   5J     � 5L     $��2��6#   
�������.+�5M  "   �� $
��Auto=�6/   .��5N  &   �� ��.  |�.  ��63   �� *
Properties+( �� *TemplatedParent+��5O  *   �� 5P  .   .R�5Q  2   $� 5R  /   5T  '   5U  #   n� 5W  "   $; PART_DragThumb��6(   $
��Left=�6@   $��5��6[   $��6,0,0,0q�6e   $< SizeWE��6v   z�5X  &   T� 5Y  *    6=   �� *NameColumnWidth+( �� *FindAncestor+"/  ��5[  &   �� 5\  *   .R�5]  .   �� 
������ 65   5^  +   5`  #   5b     �� 5d     $��3��6+   $��3��66   $��Stretch=�6C   y�6a   �� *DisplaySummary+( �� *TemplatedParent+82  �� 5e     $��4��6)   $��0,0,0,5q�66   y�6G   �� *DisplaySummary+( �� *TemplatedParent+82  .+�5f  "   �� $= 2 2 2 0q�6,   $
��Bold"�6>   ��6P   �� *SelectedProperty.Name+( �� *TemplatedParent+�� 5g  "   $= 5 2 2 0q�6,   $��WrapWithOverflow=�6>   ��6^   �� *SelectedProperty.Description+( �� *TemplatedParent+5h     5i     5j     5k     5m     5n     5p     