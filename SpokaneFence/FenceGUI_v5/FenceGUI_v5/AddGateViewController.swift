//
//  AddGateViewController.swift
//  FenceGUI_v5
//
//  Created by Tanner Orndorff on 8/2/18.
//  Copyright © 2018 Monocle Heads. All rights reserved.
//

import UIKit

class AddGateViewController: UIViewController {
    var gates = [Gate]()
    var ng: Gate?
    var ngmaterial: String?
    var ngcolor: String?
    var ngwidth: Int?
    
    @IBOutlet internal var widthdata: UITextField?
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func viewDidAppear(_ animated: Bool) {
        let width = Int((widthdata?.text)!)
        ng = Gate(id: 0, width: width! , material: ngmaterial!, color: ngcolor!)
        gates.append(ng!)
    }
    
    
}
