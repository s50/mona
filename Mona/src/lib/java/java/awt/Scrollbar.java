/*
Copyright (c) 2005 bayside

Permission is hereby granted, free of charge, to any person 
obtaining a copy of this software and associated documentation files 
(the "Software"), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, 
publish, distribute, sublicense, and/or sell copies of the Software, 
and to permit persons to whom the Software is furnished to do so, 
subject to the following conditions:

The above copyright notice and this permission notice shall be 
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

package java.awt;

import java.awt.event.AdjustmentEvent;
import java.awt.event.MouseEvent;

/**
 水平・垂直スクロールバークラス
*/
public class Scrollbar extends Component {
	/** 垂直ボタン（パレット）*/
	private int button_palette[] = {
		0xff040204,
		0xff8486dc,
		0xffdcdafc,
		0xff5456b4,
		0xffb4b2fc,
		0xfff4f2f4,
	};

	/** 垂直ボタン（データ）*/
	private byte button_data[] = {
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x5,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x4,0x0,
		0x0,0x2,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x1,0x0,
		0x0,0x2,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x1,0x0,
		0x0,0x2,0x4,0x4,0x5,0x2,0x2,0x2,0x2,0x2,0x2,0x4,0x4,0x4,0x1,0x0,
		0x0,0x2,0x4,0x4,0x4,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x4,0x4,0x1,0x0,
		0x0,0x2,0x4,0x4,0x5,0x2,0x2,0x2,0x2,0x2,0x2,0x4,0x4,0x4,0x1,0x0,
		0x0,0x2,0x4,0x4,0x4,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x4,0x4,0x1,0x0,
		0x0,0x2,0x4,0x4,0x5,0x2,0x2,0x2,0x2,0x2,0x2,0x4,0x4,0x4,0x1,0x0,
		0x0,0x2,0x4,0x4,0x4,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x4,0x4,0x1,0x0,
		0x0,0x2,0x4,0x4,0x5,0x2,0x2,0x2,0x2,0x2,0x2,0x4,0x4,0x4,0x1,0x0,
		0x0,0x2,0x4,0x4,0x4,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x4,0x4,0x1,0x0,
		0x0,0x2,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x1,0x0,
		0x0,0x2,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x1,0x0,
		0x0,0x2,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x4,0x1,0x0,
		0x0,0x4,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x0,
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	};

	/** 上向き矢印（パレット）*/
	private int arrow_palette[] = {
		0xff040204,
		0xffcccecc,
		0xfffcfefc,
		0xffe4e6e4,
	};

	/** 上向き矢印（データ）*/
	private byte arrow1_data[] = {
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x3,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x0,0x0,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x0,0x0,0x0,0x0,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x3,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x0,
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	};

	/** 下向き矢印（データ）*/
	private byte arrow2_data[] = {
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0x0,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x2,0x3,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x0,0x0,0x0,0x0,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x0,0x0,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x2,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x3,0x1,0x0,
		0x0,0x3,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x1,0x0,
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
	};
	
	/** 水平スクロールバー */
	public static final int HORIZONTAL = 0;
	/** 垂直スクロールバー */
	public static final int VERTICAL   = 1;
	
	/** スクロールバーの種類 */
	private int orientation;
	/** 最小値 */
	private int minimum;
	/** 最大値 */
	private int maximum;
	/** 一度に増減する量 */
	private int blocksize;
	/** 一つ前の値 */
	private int preValue;
	/** 現在の値 */
	private int value;
	/** ブロックイベント */
	private AdjustmentEvent adjustmentEvent;
	
	/** デフォルトコンストラクタ */
	public Scrollbar() {
		this.orientation = VERTICAL;
		this.minimum = 0;
		this.maximum = 100;
		this.blocksize = 10;
		this.preValue = 0;
		this.value = 0;
		this.adjustmentEvent = new AdjustmentEvent(AdjustmentEvent.BLOCK_INCLEMENT, this);
	}

	/** コンストラクタ */
	public Scrollbar(int orientation) {
		this.orientation = orientation;
		this.minimum = 0;
		this.maximum = 100;
		this.blocksize = 10;
		this.preValue = 0;
		this.value = 0;
		this.adjustmentEvent = new AdjustmentEvent(AdjustmentEvent.BLOCK_INCLEMENT, this);
	}

	/** 最小値を得る（初期値は0） */
	public int getMinimum() { return this.minimum; }

	/** 最大値を得る（初期値は100） */
	public int getMaximum() { return this.maximum; }

	/** 一度に増減する量を得る（初期値は10） */
	public int getBlocksize() { return this.blocksize; }

	/** 値を得る */
	public int getValue() { return this.value; }

	/** 最小値を設定する */
	public void setMinimum(int n) { this.minimum = n; }

	/** 最大値を設定する */
	public void setMaximum(int n) { this.maximum = n; }

	/** 一度に増減する量を設定する */
	public void setBlocksize(int n) { this.blocksize = n; }

	/** 値を設定する */
	public void setValue(int value) {
		if (value < this.minimum) {
			this.value = this.minimum;
		} else if (value > this.maximum) {
			this.value = this.maximum;
		} else {
			this.value = value;
		}
		repaint();
		// 減少
		if (value < this.preValue) {
			this.adjustmentEvent.setType(AdjustmentEvent.BLOCK_DECLEMENT);
			if (getParent() != null) {
				getParent().processEvent(this.adjustmentEvent);
			}
		// 増加
		} else {
			this.adjustmentEvent.setType(AdjustmentEvent.BLOCK_INCLEMENT);
			if (getParent() != null) {
				getParent().processEvent(this.adjustmentEvent);
			}
		}
		this.preValue = value;
	}

	/**
	 部品の大きさを設定する.
	 垂直スクロールバーの時は幅16固定、水平スクロールバーのときは高さ16固定。
	 それ以外の値を設定しても16になる。
	*/
	public void setBounds(int x, int y, int w, int h) {
		// 幅と高さは16固定とする
		if (this.orientation == VERTICAL) {
			super.setBounds(x, y, 16, h);
		} else {
			super.setBounds(x, y, w, 16);
		}
	}

	/** 描画ハンドラ */
	public void paint(Graphics g) {
		int w = getWidth(), h = getHeight();
		
		// 外枠
		g.setColor(Color.gray);
		g.fillRect(0,0,getWidth(),getHeight());
		g.setColor(Color.black);
		g.drawRect(0,0,getWidth(),getHeight());
		
		// 垂直スクロールバー
		if (this.orientation == VERTICAL) {
			// 上向き矢印
			for (int i = 0; i < 16; i++) {
				for (int j = 0; j < 16; j++) {
					g.drawPixel(j, i, arrow_palette[arrow1_data[i * 16 + j] & 0xFF]);
				}
			}
			// 下向き矢印
			for (int i = 0; i < 16; i++) {
				for (int j = 0; j < 16; j++) {
					g.drawPixel(j, i + h - 16, arrow_palette[arrow2_data[i * 16 + j] & 0xFF]);
				}
			}
			// ボタン
			int offset = 15 + (getHeight() - 47) * (getValue() - getMinimum()) / (getMaximum() - getMinimum());
			for (int i = 0; i < 17; i++) {
				for (int j = 0; j < 16; j++) {
					g.drawPixel(j, i + offset, button_palette[button_data[i * 16 + j] & 0xFF]);
				}
			}
		// 水平スクロールバー
		} else {
			// 左向き矢印
			for (int i = 0; i < 16; i++) {
				for (int j = 0; j < 16; j++) {
					g.drawPixel(i, j, arrow_palette[arrow1_data[i * 16 + j] & 0xFF]);
				}
			}
			// 右向き矢印
			for (int i = 0; i < 16; i++) {
				for (int j = 0; j < 16; j++) {
					g.drawPixel(i + w - 16, j, arrow_palette[arrow2_data[i * 16 + j] & 0xFF]);
				}
			}
			// ボタン
			int offset = 15 + (getWidth() - 47) * (getValue() - getMinimum()) / (getMaximum() - getMinimum());
			for (int i = 0; i < 17; i++) {
				for (int j = 0; j < 16; j++) {
					g.drawPixel(i + offset, j, button_palette[button_data[i * 16 + j] & 0xFF]);
				}
			}
		}
	}

	/** イベントハンドラ */
	public void processEvent(AWTEvent event) {
		if (event.getType() == MouseEvent.MOUSE_PRESSED) {
			MouseEvent me = (MouseEvent)event;
			int mx = me.getX();
			int my = me.getY();
			// 垂直スクロールバー
			if (this.orientation == VERTICAL) {
				if (0 < my && my < 16) {
					setValue(this.value - this.blocksize);
				} else if (getHeight() - 16 < my && my < getHeight()) {
					setValue(this.value + this.blocksize);
				}
			// 水平スクロールバー
			} else {
				if (0 < mx && mx < 16) {
					setValue(this.value - this.blocksize);
				} else if (getWidth() - 16 < mx && mx < getWidth()) {
					setValue(this.value + this.blocksize);
				}
			}
		} else if (event.getType() == MouseEvent.MOUSE_DRAGGED) {
			MouseEvent me = (MouseEvent)event;
			int mx = me.getX();
			int my = me.getY();
			// 垂直スクロールバー
			if (this.orientation == VERTICAL && 16 <= my && my <= getHeight() - 16) {
				setValue((my - 16) * (getMaximum() - getMinimum()) / (getHeight() - 32) + getMinimum());
			// 水平スクロールバー
			} else if (this.orientation == HORIZONTAL && 16 <= mx && mx <= getWidth() - 16) {
				setValue((mx - 16) * (getMaximum() - getMinimum()) / (getWidth() - 32) + getMinimum());
			}
		}
	}
}
