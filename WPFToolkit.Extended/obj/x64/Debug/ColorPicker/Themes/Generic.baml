   M S B A M L   `   `   `  ����N  JWPFToolkit.Extended, Version=1.4.0.0, Culture=neutral, PublicKeyToken=nullG(clr-namespace:Microsoft.Windows.ControlsMicrosoft.Windows.Controls  5      g8clr-namespace:Microsoft.Windows.Controls.Core.Converters*Microsoft.Windows.Controls.Core.Converters  5      W0clr-namespace:Microsoft.Windows.Controls.Chromes"Microsoft.Windows.Controls.Chromes  5      \ XPresentationFramework, Version=3.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=3.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=3.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35   ButtonHover  �� Color  ButtonHoverBorder  ButtonChecked  ButtonPressed  ButtonPressedBorder   BooleanToVisibilityConverterE    ?Microsoft.Windows.Controls.Core.Converters.InverseBoolConverter  InverseBoolConverterP   JMicrosoft.Windows.Controls.Core.Converters.ColorToSolidColorBrushConverter # ColorToSolidColorBrushConverter  ColorPickerDarkBorderBrush �� EndPoint �� 
StartPoint � Color � Offset 	 PopupBackgroundBrush 
 CheckerBrush j� Viewport j� ViewportUnits j� TileMode L� Drawing	 � Brush
 � Geometry �� Rect  ColorPaletteLisBoxStyle �� 
TargetType �� Property �� Value �� 
TargetType � ToolTip ��Name �� Triggers P� Property P� Value �� 
TargetName  ColorItemTemplate �� 	Converter �� Triggers �� Binding �� Value   ColorPickerToggleButtonStyle J� SnapsToDevicePixels5   /Microsoft.Windows.Controls.Chromes.ButtonChrome  Name J� IsMouseOver   RenderMouseOver   RenderPressed   RenderChecked  �� RelativeSource! �� Mode" �� AncestorType#   RenderEnabled$ � ColumnDefinitions% �Name& J� IsHitTestVisible  ColorDisplayStyle,   &Microsoft.Windows.Controls.ColorPicker' d�Name(   ButtonStyle) d� 	IsChecked* �� Mode+ �� Orientation, �Name- � 	StaysOpen. � AllowsTransparency/ � HorizontalOffset0 � VerticalOffset1 �� ElementName2 �� Path3 �� Padding4 � RowDefinitions5 �� 	Converter6 �� Padding7 ��Name8 �� SelectionMode,   &Microsoft.Windows.Controls.ColorCanvas9  Name:   SelectedColor; P� 
SourceName�� 5      D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    8x,http://schemas.microsoft.com/winfx/2006/xaml    5      2local(clr-namespace:Microsoft.Windows.Controls  5      KcoreConverters8clr-namespace:Microsoft.Windows.Controls.Core.Converters  5      ;chrome0clr-namespace:Microsoft.Windows.Controls.Chromes  5      %S  &	        &	 !     &	 B     &	 c     &	 �     &	 �     &	 �     &	 �     &	 �     &		 �    &	
 �    &	 �    &	 j    7  7 
 &	 �    &	 �    7  7 
 '  �    7  7  7  7  7  7 	 7  7  7  7  7  7  7  7  7  7  7  �� 5      $  #C2E0FF��6*   �� 5      $  #3399FF��60   �� 5	      $  #E6F0FA��6,   �� 5
      $  #99CCFF��6,   �� 5      $  #3399FF��62   �� 5      6#      5      6*     5      65   �� 5      $ 0.5,1&�6=   $ 0.5,0&�6N   .��5   
   � $ 	#FFA3AEB9��6   $ 0Q�6)   � 5   
   $ 	#FF8399A9��6   $ 0.375Q�6)   � 5   
   $ 	#FF718597��6   $ 0.375Q�6)   � 5   
   $ 	#FF617584��6   $ 1Q�6)   5      �� 5      $	 0,0&�67   $	 0,1&�6H   ��5      � � 5      $ 0Q�6   $ 	#FFffffff��6*   � 5       $ 1Q�6   $ 	#FFE8EBED��6*   5!      5#      L� 5%      $ 	0,0,10,10�6)   $ Absolute=�6>   $
 Tile=�6W    5&   
   I� 5'      .��5(      � 
	 �����
 5)      �� 5*      $ 0,0 100,100�6,   5,      � 5-      
	 �����
 5.      � 5/      .��50      �� $ 	0,0 50,50�60   �� 51      $ 50,50 50,50�60   52      54      55      57      �� 59      " ��6,   .�5:   
   ��  �@�ToolTip 6$   �� *Name+�� 5;   
    � �� 5<      �� 5=      " ��6"   .R�5>      �  6   �� *Name+.+�5?      �� $��Center=�6+   $��Center=�6H   �� 5@      $ _outerBorder��6h   $��1q�6!   
������ 
������ $��Stretch=�6~   $��Stretch=�6�   ._�5A      �� $ _innerBorder��6l   
������ $��1q�6>   
������ $��Stretch=�6�   $��Stretch=�6�   5B      5C       5D      P� 5E       �@J�IsMouseOver . . �5F      �� $ _outerBorder��6%    � �� �	#FFFF00006V   �� 5G      $ _innerBorder��6%    � �� �	#FFFFFF006V   5H      P� 5I       �@��
IsSelected . . �5J      �� $ _outerBorder��6%    � �� �	#FFFF00006V   �� 5K      $ _innerBorder��6%    � �� �	#FFFFFF006V   5L      5N      5P      5Q      �� 5S      .R�5T   
   � .+�5U      �� ���	#FFC9CACA$��1q�6-   $��2,2,2,2q�6A   ._�5V      �� $��14��6   $��14��6'   ��5W      �� 5X      " ��6    .�5Y      ��  � �� 65   �� *Color+8    5Z      �� 5[   "    6.   �� *Name+ Transparent6G   .a�5\   &   ��  � ��8  6=   5]   #   5_      5a      5b      5c      5d      �� 5f      " d�61   .�5g   
   ��  � �� 5h      �� 5i      " d�6"   .R�5j      �  . .+�5k        $ ToggleButtonChrome��6.   # z 5n      # z��5o       5l   -   �� *IsOpen+  �� $! FindAncestor=�$" local:ColorPickerL�# 5m   -   �� *	IsEnabled+  �� $! FindAncestor=�$" local:ColorPickerL�5o      � 5q      $ 5r      �� 5s   "   $��* �63   �� 5t   "   $
��Auto �63   .+�5w      �� $��Stretch=�6/   $��Stretch=�6M   # z 6i   � 5y      $% 
arrowGlyph��6#   & .  $��1��6P   $��5q�6`   .+�5z   "   F� $��7��6'   $��4��61   �����    @B �    @B �        ��- ��- ���-     ��- ��- ���- @B  	=  	= � 	= @B  	=  	= � 	=     ��j ��j ���j     ��j ��j ���j @B ��[ ��[ Ӏ�[ @B ��[ �� ��[ �� Ӏ�[ �� @KL �� @KL �� �@KL �� @KL ��- @KL ��- �@KL ��-  	= ��-  	= ��- � 	= ��-  	=  	=  	=  	= � 	=  	= ��-  	= ��-  	= ���-  	= ��- ��- ��- ��- ���- ��- �� ��- �� ��- Ӏ� ��- �� �� �� �� Ӏ� �� �� �� �@B �� �@B @B 	���	#FF0000006<  5{      5|      5}      5~      5�      5�      �� 5�      " ��6&   .�5�   
   ��  � �� 6'   �� *SelectedColor+  �� *TemplatedParent+8    5�   
   �� 5�       6   �� *SelectedColor+  �� *TemplatedParent+ Transparent6m   .a�5�      ��  � ��8  6/   5�      5�      �� 5�      "  6   .�5�   
   ��  � ��8   6(   �� 5�   
    � ��$ 1q�6,   �� 5�   
    �@ ButtonStyle8  6(   �� 5�   
    � |� .  6&   �� 5�   
    � �� 5�      �� 5�      "  6"   .R�5�      � .+�5�      d� $"' PART_ColorPickerToggleButton��6'   ��. $��22��6^   #��z( 5�   '   ) 5�   m   �� *IsOpen+  �� *TemplatedParent+$* TwoWay=�& 5�   '   �� *IsOpen+  �� *TemplatedParent+8  .��5�      � $��2,2,0,2q�6#   .+�5�   "   �� $ 	ColorOnly��6)   8�� 6<   �� 5�   "   $ ColorAndName��6)   
�������$y�Hidden=�6R   ._�5�   &   �� $+ 
Horizontal=�61   .+�5�   *   �� $
��Left=�61   $��20��6L   $��2,1,4,1q�6W   8�� $��1q�6�   ���	#FFC9CACA6�   �� 5�   *   $��Center=�6�   ��64   �� *SelectedColorText+  �� *TemplatedParent+6�   5�   '   5�   #   5�      5�      � 5�      $", PART_ColorPickerPalettePopup��6    $��Bottom=�6G   - .  . . |�.  $/ 1��6�   $0 1��6  ��6b   �� $"1 PART_ColorPickerToggleButton��$2 	IsChecked�.��5�      �� $��1q�6%   8�� 8�� $3 3q�6�   ._�5�   "   � 4 5�   &   �� 5�   *   $
��Auto �68   �� 5�   *   �� 5�   *   $
��Auto �68   .+�5�   &   � $% _gridStandardColorsHost��6+   $��4q�6L   4 5�   *   �� 5�   .   $
��Auto �6<   �� 5�   .   $
��Auto �6<   �� 5�   .   $
��Auto �6<   �� 5�   .   $
��Auto �6<   .+�5�   *   � $��1��6/   y�6<   �� *ShowAvailableColors+85  .+�5�   .   � 4 5�   2   �� 5�   6   $
��Auto �6D   �� 5�   6   .+�5�   2   �� $��Available Colors��6<   
�������$6 2q�6k   $��0,0,0,1q�6w   �� 5�   2   $7 PART_AvailableColors��6:   $��1��6X   
������ $��0q�6~   $8 Single=�6�   8�� 8��	 ��5�   :   �� *AvailableColors+  �� *TemplatedParent+��5�   :   Z� ��5�   6   �� 5�   :   .R�5�   >   � $	��200��6H   5�   ;   5�   3   5�   /   5�   +   � 5�   *   $��2��6/   y�6<   �� *ShowStandardColors+85 
 .+�5�   .   � 4 5�   2   �� 5�   6   $
��Auto �6D   �� 5�   6   $
��Auto �6D   .+�5�   2   �� $��Standard Colors��6<   
�������$6 2q�6j   $��0,1,0,1q�6v   �� 5�   2   $7 PART_StandardColors��6:   $��1��6W   $8 Single=�6d   
������ $��0q�6�   8�� 8�� ��5�   :   �� *StandardColors+  �� *TemplatedParent+��5�   :   Z� ��5�   6   �� 5�   :   .R�5�   >   � $	��200��6H   5�   ;   5�   3   5�   /   5�   +   � 5�   *   $��3��6/   $��0,1,0,1q�6<   y�6M   �� *ShowRecentColors+85  .+�5�   .   � 4 5�   2   �� 5�   6   $
��Auto �6D   �� 5�   6   $
��Auto �6D   .+�5�   2   �� $��Recent Colors��6<   
�������$6 2q�6h   $��0,1,0,1q�6t   �� 5�   2   $7 PART_RecentColors��6:   $��1��6U   $8 Single=�6c   
������ $��0q�6�   8�� 8�� ��5�   :   �� *RecentColors+  �� *TemplatedParent+��5�   :   Z� ��5�   6   �� 5�   :   .R�5�   >   � $	��200��6H   5�   ;   5�   3   5�   /   5�   +   5�   '   � 5�   &   $% _colorCanvasHost��6+   $y�	Collapsed=�6E   .+�5�   *     $9 PART_ColorCanvas��6<   
������ $��0q�6o   : 5�   <   �� *SelectedColor+  �� *TemplatedParent+5�   '   �� 5�   &   $��1��60   $��Stretch=�6=   $��5,0,5,0q�6[   d� 5  &   $' 
_colorMode��63   $��2��6G   $��Advanced��6T   $��5q�6g   y�6r   �� *ShowAdvancedButton+85  5  #   5     5     5      5     P� 5      �@ DisplayColorAndName . . �5     �� $ 	ColorOnly��6%    � y�$ 	Collapsed=�6R   �� 5	     $ ColorAndName��6%    � y�$ Visible=�6U   5
     P� 5     $; 
_colorMode��6"    �@d�	IsChecked$
 TrueY�6O   . �5     �� $ 
_colorMode��6%    � ��$ Standard��6P   �� 5     $ _colorCanvasHost��6%    � y�$ Visible=�6Y   �� 5     $ _gridStandardColorsHost��6%    � y�$ 	Collapsed=�6`   5     5     5     5     5     