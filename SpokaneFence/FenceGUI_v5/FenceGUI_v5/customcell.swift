//
//  estimate.swift
//  FenceGUI_v5
//
//  Created by Tanner Orndorff on 7/9/18.
//  Copyright © 2018 Monocle Heads. All rights reserved.
//

import UIKit

class customcell: UITableViewCell {
    
    var cus: Customer?
    var name: String?
    var address: String?
    var id: Int?
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
   /* public class customview: UIView {
        var shouldSetupConstraints = true
        var addressView: UILabel
        var phone_numView: UILabel
        
        override init(frame: CGRect) {
            self.addressView = UILabel(frame: CGRect.zero)
            self.phone_numView = UILabel(frame: CGRect.zero)
            super.init(frame: frame)
            addressView.textColor = UIColor.black
            addressView.font = UIFont.systemFont(ofSize:17)
            addressView.textAlignment = NSTextAlignment.left
            addressView.lineBreakMode = NSLineBreakMode.byTruncatingTail
            addSubview(self.addressView)
            phone_numView.textColor = UIColor.black
            phone_numView.font = UIFont.systemFont(ofSize:17)
            phone_numView.textAlignment = NSTextAlignment.left
            phone_numView.lineBreakMode = NSLineBreakMode.byTruncatingTail
            addSubview(self.phone_numView)
        }
        
        required public init?(coder aDecoder: NSCoder) {
            fatalError("init(coder:) has not been implemented")
        }
        
        override func updateConstraints() {
            if(shouldSetupConstraints) {
                // AutoLayout constraints
                shouldSetupConstraints = false
            }
            super.updateConstraints()
        }
    }
*/
}
